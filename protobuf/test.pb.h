// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef PROTOBUF_test_2eproto__INCLUDED
#define PROTOBUF_test_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace test {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_test_2eproto();
void protobuf_AssignDesc_test_2eproto();
void protobuf_ShutdownFile_test_2eproto();

class TestMessage;

// ===================================================================

class TestMessage : public ::google::protobuf::Message {
 public:
  TestMessage();
  virtual ~TestMessage();

  TestMessage(const TestMessage& from);

  inline TestMessage& operator=(const TestMessage& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TestMessage& default_instance();

  void Swap(TestMessage* other);

  // implements Message ----------------------------------------------

  inline TestMessage* New() const { return New(NULL); }

  TestMessage* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TestMessage& from);
  void MergeFrom(const TestMessage& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(TestMessage* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 int_field = 1;
  void clear_int_field();
  static const int kIntFieldFieldNumber = 1;
  ::google::protobuf::int32 int_field() const;
  void set_int_field(::google::protobuf::int32 value);

  // optional bytes byte_field = 2;
  void clear_byte_field();
  static const int kByteFieldFieldNumber = 2;
  const ::std::string& byte_field() const;
  void set_byte_field(const ::std::string& value);
  void set_byte_field(const char* value);
  void set_byte_field(const void* value, size_t size);
  ::std::string* mutable_byte_field();
  ::std::string* release_byte_field();
  void set_allocated_byte_field(::std::string* byte_field);

  // @@protoc_insertion_point(class_scope:test.TestMessage)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr byte_field_;
  ::google::protobuf::int32 int_field_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_test_2eproto();
  friend void protobuf_AssignDesc_test_2eproto();
  friend void protobuf_ShutdownFile_test_2eproto();

  void InitAsDefaultInstance();
  static TestMessage* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// TestMessage

// optional int32 int_field = 1;
inline void TestMessage::clear_int_field() {
  int_field_ = 0;
}
inline ::google::protobuf::int32 TestMessage::int_field() const {
  // @@protoc_insertion_point(field_get:test.TestMessage.int_field)
  return int_field_;
}
inline void TestMessage::set_int_field(::google::protobuf::int32 value) {
  
  int_field_ = value;
  // @@protoc_insertion_point(field_set:test.TestMessage.int_field)
}

// optional bytes byte_field = 2;
inline void TestMessage::clear_byte_field() {
  byte_field_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& TestMessage::byte_field() const {
  // @@protoc_insertion_point(field_get:test.TestMessage.byte_field)
  return byte_field_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TestMessage::set_byte_field(const ::std::string& value) {
  
  byte_field_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:test.TestMessage.byte_field)
}
inline void TestMessage::set_byte_field(const char* value) {
  
  byte_field_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:test.TestMessage.byte_field)
}
inline void TestMessage::set_byte_field(const void* value, size_t size) {
  
  byte_field_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:test.TestMessage.byte_field)
}
inline ::std::string* TestMessage::mutable_byte_field() {
  
  // @@protoc_insertion_point(field_mutable:test.TestMessage.byte_field)
  return byte_field_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* TestMessage::release_byte_field() {
  
  return byte_field_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void TestMessage::set_allocated_byte_field(::std::string* byte_field) {
  if (byte_field != NULL) {
    
  } else {
    
  }
  byte_field_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), byte_field);
  // @@protoc_insertion_point(field_set_allocated:test.TestMessage.byte_field)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_test_2eproto__INCLUDED
