// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: protos/image_service.proto
// Protobuf C++ Version: 5.27.2

#include "protos/image_service.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace image_service {
      template <typename>
PROTOBUF_CONSTEXPR SetImageResponse::SetImageResponse(::_pbi::ConstantInitialized) {}
struct SetImageResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR SetImageResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~SetImageResponseDefaultTypeInternal() {}
  union {
    SetImageResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 SetImageResponseDefaultTypeInternal _SetImageResponse_default_instance_;

inline constexpr SetImageRequest::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : user_id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        image_data_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR SetImageRequest::SetImageRequest(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct SetImageRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR SetImageRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~SetImageRequestDefaultTypeInternal() {}
  union {
    SetImageRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 SetImageRequestDefaultTypeInternal _SetImageRequest_default_instance_;

inline constexpr ImageResponse::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : image_data_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR ImageResponse::ImageResponse(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct ImageResponseDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ImageResponseDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ImageResponseDefaultTypeInternal() {}
  union {
    ImageResponse _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ImageResponseDefaultTypeInternal _ImageResponse_default_instance_;

inline constexpr ImageRequest::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : user_id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR ImageRequest::ImageRequest(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct ImageRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ImageRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ImageRequestDefaultTypeInternal() {}
  union {
    ImageRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ImageRequestDefaultTypeInternal _ImageRequest_default_instance_;
}  // namespace image_service
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_protos_2fimage_5fservice_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_protos_2fimage_5fservice_2eproto = nullptr;
const ::uint32_t
    TableStruct_protos_2fimage_5fservice_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::image_service::ImageRequest, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::image_service::ImageRequest, _impl_.user_id_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::image_service::ImageResponse, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::image_service::ImageResponse, _impl_.image_data_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::image_service::SetImageRequest, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::image_service::SetImageRequest, _impl_.user_id_),
        PROTOBUF_FIELD_OFFSET(::image_service::SetImageRequest, _impl_.image_data_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::image_service::SetImageResponse, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::image_service::ImageRequest)},
        {9, -1, -1, sizeof(::image_service::ImageResponse)},
        {18, -1, -1, sizeof(::image_service::SetImageRequest)},
        {28, -1, -1, sizeof(::image_service::SetImageResponse)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::image_service::_ImageRequest_default_instance_._instance,
    &::image_service::_ImageResponse_default_instance_._instance,
    &::image_service::_SetImageRequest_default_instance_._instance,
    &::image_service::_SetImageResponse_default_instance_._instance,
};
const char descriptor_table_protodef_protos_2fimage_5fservice_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\032protos/image_service.proto\022\rimage_serv"
    "ice\"\037\n\014ImageRequest\022\017\n\007user_id\030\001 \001(\t\"#\n\r"
    "ImageResponse\022\022\n\nimage_data\030\001 \001(\014\"6\n\017Set"
    "ImageRequest\022\017\n\007user_id\030\001 \001(\t\022\022\n\nimage_d"
    "ata\030\002 \001(\014\"\022\n\020SetImageResponse2\242\001\n\014ImageS"
    "ervice\022E\n\010GetImage\022\033.image_service.Image"
    "Request\032\034.image_service.ImageResponse\022K\n"
    "\010SetImage\022\036.image_service.SetImageReques"
    "t\032\037.image_service.SetImageResponseb\006prot"
    "o3"
};
static ::absl::once_flag descriptor_table_protos_2fimage_5fservice_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_protos_2fimage_5fservice_2eproto = {
    false,
    false,
    362,
    descriptor_table_protodef_protos_2fimage_5fservice_2eproto,
    "protos/image_service.proto",
    &descriptor_table_protos_2fimage_5fservice_2eproto_once,
    nullptr,
    0,
    4,
    schemas,
    file_default_instances,
    TableStruct_protos_2fimage_5fservice_2eproto::offsets,
    file_level_enum_descriptors_protos_2fimage_5fservice_2eproto,
    file_level_service_descriptors_protos_2fimage_5fservice_2eproto,
};
namespace image_service {
// ===================================================================

class ImageRequest::_Internal {
 public:
};

ImageRequest::ImageRequest(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:image_service.ImageRequest)
}
inline PROTOBUF_NDEBUG_INLINE ImageRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::image_service::ImageRequest& from_msg)
      : user_id_(arena, from.user_id_),
        _cached_size_{0} {}

ImageRequest::ImageRequest(
    ::google::protobuf::Arena* arena,
    const ImageRequest& from)
    : ::google::protobuf::Message(arena) {
  ImageRequest* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:image_service.ImageRequest)
}
inline PROTOBUF_NDEBUG_INLINE ImageRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : user_id_(arena),
        _cached_size_{0} {}

inline void ImageRequest::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
ImageRequest::~ImageRequest() {
  // @@protoc_insertion_point(destructor:image_service.ImageRequest)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void ImageRequest::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.user_id_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
ImageRequest::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(ImageRequest, _impl_._cached_size_),
              false,
          },
          &ImageRequest::MergeImpl,
          &ImageRequest::kDescriptorMethods,
          &descriptor_table_protos_2fimage_5fservice_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 42, 2> ImageRequest::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_ImageRequest_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::image_service::ImageRequest>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string user_id = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(ImageRequest, _impl_.user_id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string user_id = 1;
    {PROTOBUF_FIELD_OFFSET(ImageRequest, _impl_.user_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\32\7\0\0\0\0\0\0"
    "image_service.ImageRequest"
    "user_id"
  }},
};

PROTOBUF_NOINLINE void ImageRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:image_service.ImageRequest)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.user_id_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* ImageRequest::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:image_service.ImageRequest)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string user_id = 1;
  if (!this->_internal_user_id().empty()) {
    const std::string& _s = this->_internal_user_id();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "image_service.ImageRequest.user_id");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:image_service.ImageRequest)
  return target;
}

::size_t ImageRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:image_service.ImageRequest)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string user_id = 1;
  if (!this->_internal_user_id().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_user_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void ImageRequest::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<ImageRequest*>(&to_msg);
  auto& from = static_cast<const ImageRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:image_service.ImageRequest)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_user_id().empty()) {
    _this->_internal_set_user_id(from._internal_user_id());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ImageRequest::CopyFrom(const ImageRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:image_service.ImageRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void ImageRequest::InternalSwap(ImageRequest* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.user_id_, &other->_impl_.user_id_, arena);
}

::google::protobuf::Metadata ImageRequest::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class ImageResponse::_Internal {
 public:
};

ImageResponse::ImageResponse(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:image_service.ImageResponse)
}
inline PROTOBUF_NDEBUG_INLINE ImageResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::image_service::ImageResponse& from_msg)
      : image_data_(arena, from.image_data_),
        _cached_size_{0} {}

ImageResponse::ImageResponse(
    ::google::protobuf::Arena* arena,
    const ImageResponse& from)
    : ::google::protobuf::Message(arena) {
  ImageResponse* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:image_service.ImageResponse)
}
inline PROTOBUF_NDEBUG_INLINE ImageResponse::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : image_data_(arena),
        _cached_size_{0} {}

inline void ImageResponse::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
ImageResponse::~ImageResponse() {
  // @@protoc_insertion_point(destructor:image_service.ImageResponse)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void ImageResponse::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.image_data_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
ImageResponse::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(ImageResponse, _impl_._cached_size_),
              false,
          },
          &ImageResponse::MergeImpl,
          &ImageResponse::kDescriptorMethods,
          &descriptor_table_protos_2fimage_5fservice_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 0, 2> ImageResponse::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_ImageResponse_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::image_service::ImageResponse>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // bytes image_data = 1;
    {::_pbi::TcParser::FastBS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(ImageResponse, _impl_.image_data_)}},
  }}, {{
    65535, 65535
  }}, {{
    // bytes image_data = 1;
    {PROTOBUF_FIELD_OFFSET(ImageResponse, _impl_.image_data_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBytes | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
  }},
};

PROTOBUF_NOINLINE void ImageResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:image_service.ImageResponse)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.image_data_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* ImageResponse::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:image_service.ImageResponse)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // bytes image_data = 1;
  if (!this->_internal_image_data().empty()) {
    const std::string& _s = this->_internal_image_data();
    target = stream->WriteBytesMaybeAliased(1, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:image_service.ImageResponse)
  return target;
}

::size_t ImageResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:image_service.ImageResponse)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // bytes image_data = 1;
  if (!this->_internal_image_data().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                    this->_internal_image_data());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void ImageResponse::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<ImageResponse*>(&to_msg);
  auto& from = static_cast<const ImageResponse&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:image_service.ImageResponse)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_image_data().empty()) {
    _this->_internal_set_image_data(from._internal_image_data());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ImageResponse::CopyFrom(const ImageResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:image_service.ImageResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void ImageResponse::InternalSwap(ImageResponse* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.image_data_, &other->_impl_.image_data_, arena);
}

::google::protobuf::Metadata ImageResponse::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class SetImageRequest::_Internal {
 public:
};

SetImageRequest::SetImageRequest(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:image_service.SetImageRequest)
}
inline PROTOBUF_NDEBUG_INLINE SetImageRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::image_service::SetImageRequest& from_msg)
      : user_id_(arena, from.user_id_),
        image_data_(arena, from.image_data_),
        _cached_size_{0} {}

SetImageRequest::SetImageRequest(
    ::google::protobuf::Arena* arena,
    const SetImageRequest& from)
    : ::google::protobuf::Message(arena) {
  SetImageRequest* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:image_service.SetImageRequest)
}
inline PROTOBUF_NDEBUG_INLINE SetImageRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : user_id_(arena),
        image_data_(arena),
        _cached_size_{0} {}

inline void SetImageRequest::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
SetImageRequest::~SetImageRequest() {
  // @@protoc_insertion_point(destructor:image_service.SetImageRequest)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void SetImageRequest::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.user_id_.Destroy();
  _impl_.image_data_.Destroy();
  _impl_.~Impl_();
}

const ::google::protobuf::MessageLite::ClassData*
SetImageRequest::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(SetImageRequest, _impl_._cached_size_),
              false,
          },
          &SetImageRequest::MergeImpl,
          &SetImageRequest::kDescriptorMethods,
          &descriptor_table_protos_2fimage_5fservice_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<1, 2, 0, 45, 2> SetImageRequest::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    2, 8,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967292,  // skipmap
    offsetof(decltype(_table_), field_entries),
    2,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_SetImageRequest_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::image_service::SetImageRequest>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // bytes image_data = 2;
    {::_pbi::TcParser::FastBS1,
     {18, 63, 0, PROTOBUF_FIELD_OFFSET(SetImageRequest, _impl_.image_data_)}},
    // string user_id = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(SetImageRequest, _impl_.user_id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string user_id = 1;
    {PROTOBUF_FIELD_OFFSET(SetImageRequest, _impl_.user_id_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // bytes image_data = 2;
    {PROTOBUF_FIELD_OFFSET(SetImageRequest, _impl_.image_data_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBytes | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\35\7\0\0\0\0\0\0"
    "image_service.SetImageRequest"
    "user_id"
  }},
};

PROTOBUF_NOINLINE void SetImageRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:image_service.SetImageRequest)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.user_id_.ClearToEmpty();
  _impl_.image_data_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

::uint8_t* SetImageRequest::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:image_service.SetImageRequest)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  // string user_id = 1;
  if (!this->_internal_user_id().empty()) {
    const std::string& _s = this->_internal_user_id();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "image_service.SetImageRequest.user_id");
    target = stream->WriteStringMaybeAliased(1, _s, target);
  }

  // bytes image_data = 2;
  if (!this->_internal_image_data().empty()) {
    const std::string& _s = this->_internal_image_data();
    target = stream->WriteBytesMaybeAliased(2, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:image_service.SetImageRequest)
  return target;
}

::size_t SetImageRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:image_service.SetImageRequest)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::_pbi::Prefetch5LinesFrom7Lines(reinterpret_cast<const void*>(this));
  // string user_id = 1;
  if (!this->_internal_user_id().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_user_id());
  }

  // bytes image_data = 2;
  if (!this->_internal_image_data().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                    this->_internal_image_data());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}


void SetImageRequest::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<SetImageRequest*>(&to_msg);
  auto& from = static_cast<const SetImageRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:image_service.SetImageRequest)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_user_id().empty()) {
    _this->_internal_set_user_id(from._internal_user_id());
  }
  if (!from._internal_image_data().empty()) {
    _this->_internal_set_image_data(from._internal_image_data());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void SetImageRequest::CopyFrom(const SetImageRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:image_service.SetImageRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void SetImageRequest::InternalSwap(SetImageRequest* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.user_id_, &other->_impl_.user_id_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.image_data_, &other->_impl_.image_data_, arena);
}

::google::protobuf::Metadata SetImageRequest::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class SetImageResponse::_Internal {
 public:
};

SetImageResponse::SetImageResponse(::google::protobuf::Arena* arena)
    : ::google::protobuf::internal::ZeroFieldsBase(arena) {
  // @@protoc_insertion_point(arena_constructor:image_service.SetImageResponse)
}
SetImageResponse::SetImageResponse(
    ::google::protobuf::Arena* arena,
    const SetImageResponse& from)
    : ::google::protobuf::internal::ZeroFieldsBase(arena) {
  SetImageResponse* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);

  // @@protoc_insertion_point(copy_constructor:image_service.SetImageResponse)
}

const ::google::protobuf::MessageLite::ClassData*
SetImageResponse::GetClassData() const {
  PROTOBUF_CONSTINIT static const ::google::protobuf::MessageLite::
      ClassDataFull _data_ = {
          {
              &_table_.header,
              nullptr,  // OnDemandRegisterArenaDtor
              nullptr,  // IsInitialized
              PROTOBUF_FIELD_OFFSET(SetImageResponse, _impl_._cached_size_),
              false,
          },
          &SetImageResponse::MergeImpl,
          &SetImageResponse::kDescriptorMethods,
          &descriptor_table_protos_2fimage_5fservice_2eproto,
          nullptr,  // tracker
      };
  ::google::protobuf::internal::PrefetchToLocalCache(&_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_data_.tc_table);
  return _data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 0, 0, 0, 2> SetImageResponse::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    0, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967295,  // skipmap
    offsetof(decltype(_table_), field_names),  // no field_entries
    0,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    &_SetImageResponse_default_instance_._instance,
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::image_service::SetImageResponse>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
  }}, {{
    65535, 65535
  }},
  // no field_entries, or aux_entries
  {{
  }},
};









::google::protobuf::Metadata SetImageResponse::GetMetadata() const {
  return ::google::protobuf::internal::ZeroFieldsBase::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace image_service
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_protos_2fimage_5fservice_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
