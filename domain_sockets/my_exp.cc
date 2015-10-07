#include <stdio.h>
#include <dbus/dbus.h>
#include <unistd.h>
#include <iostream>

DBusConnection* conn;
DBusError err;
int OpenServer() {
  dbus_error_init(&err);
  conn = dbus_bus_get(DBUS_BUS_SYSTEM, &err);
  if (dbus_error_is_set(&err)) {
    std::cout << "Conncection error" << err.message << std::endl;
  }
  if (conn == NULL) return 1;
  // request a name on the bus
  int ret = dbus_bus_request_name(conn, "test.method.server",
                                  DBUS_NAME_FLAG_REPLACE_EXISTING, &err);
  if (dbus_error_is_set(&err)) {
    std::cout << "Errors" << err.message << std::endl;
    dbus_error_free(&err);
  }
  if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret) return 1;

}

void SendSignal() {
  dbus_uint32_t serial = 0; // unique number to associate replies with requests
   DBusMessage* msg;
   DBusMessageIter args;

   // create a signal and check for errors
   msg = dbus_message_new_signal("/test/signal/Object", // object name of the signal
         "test.signal.Type", // interface name of the signal
         "Test"); // name of the signal
   if (NULL == msg)
   {
      fprintf(stderr, "Message Null\n");
return;
   }

   // append arguments onto signal
   dbus_message_iter_init_append(msg, &args);
   const char* sigvalue  = "MyTestSigVal";
   if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &sigvalue)) {
      fprintf(stderr, "Out Of Memory!\n");
	return ;
   }

   // send the message and flush the connection
   if (!dbus_connection_send(conn, msg, &serial)) {
      fprintf(stderr, "Out Of Memory!\n");
      return ;
   }
   dbus_connection_flush(conn);

   // free the message
   dbus_message_unref(msg);

}


void WaitSignal() {
	// add a rule for which messages we want to see
   DBusMessage* msg;
   DBusMessageIter args;
   dbus_bus_add_match(conn,
         "type='signal',interface='test.signal.Type'",
         &err); // see signals from the given interface
   dbus_connection_flush(conn);
   if (dbus_error_is_set(&err)) {
      fprintf(stderr, "Match Error (%s)\n", err.message);
      return ;
   }
// loop listening for signals being emmitted
   while (true) {

      // non blocking read of the next available message
      dbus_connection_read_write(conn, 50);
      msg = dbus_connection_pop_message(conn);

      // loop again if we haven't read a message
      if (NULL == msg) continue;

      // check if the message is a signal from the correct interface and with the correct name
      if (dbus_message_is_signal(msg, "test.signal.Type", "Test")) {
         // read the parameters
         if (!dbus_message_iter_init(msg, &args))
            fprintf(stderr, "Message has no arguments!\n");
         else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args))
            fprintf(stderr, "Argument is not string!\n");
         else {
   	    const char* sigvalue  = "MyTestSigVal";
            dbus_message_iter_get_basic(&args, &sigvalue);
            printf("Got Signal with value %s\n", sigvalue);
         }
      }

      // free the message
      dbus_message_unref(msg);
   }

}

int main() {
OpenServer();
SendSignal();
return 0;
}
