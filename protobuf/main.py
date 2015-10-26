import test_pb2
import sys
work = sys.argv[1]
f = open(sys.argv[2], "r+")
data = f.read()
f.close()
if work == "gen_mess":
	test_obj = test_pb2.TestMessage()
	test_obj.int_field = len(data)
	test_obj.byte_field = data
	print("create message")
	print('len = ', test_obj.int_field)
	print("data = ", " ".join("{:02X}".format(ord(c)) for c in test_obj.byte_field))
	f = open("proto_message", "wb")
	res = test_obj.SerializeToString()
	f.write(res)
	f.close()
if work ==  "parce_mess":
	test_obj = test_pb2.TestMessage()
	test_obj.ParseFromString(data)
	print("Read message")
	print('len = ', test_obj.int_field)
	print("data = ", " ".join("{:02X}".format(ord(c)) for c in test_obj.byte_field))
