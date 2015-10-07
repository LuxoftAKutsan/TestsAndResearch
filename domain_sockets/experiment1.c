#include <stdio.h>
#include <dbus/dbus.h>
#include <unistd.h>
#include <iostream>

DBusHandlerResult signal_filter(DBusConnection *connection, DBusMessage *msg,
                                void *user_data) {
  std::cout << "SomeSignal" << std::endl;
  return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
}

int main() {
  DBusError error;

  dbus_error_init(&error);
  DBusConnection *conn = dbus_bus_get(DBUS_BUS_SYSTEM, &error);

  if (dbus_error_is_set(&error)) {
    dbus_error_free(&error);
    return 1;
  }

  char *rule = "type='signal'";
  dbus_bus_add_match(conn, rule, &error);

  if (dbus_error_is_set(&error)) {
    dbus_error_free(&error);
    return 1;
  }

  dbus_connection_add_filter(conn, signal_filter, NULL, NULL);
  pause();

  return 0;
}
