package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", native_cc_proto_library = "cc_proto_library")
load("@rules_proto//proto:defs.bzl", "proto_lang_toolchain", "proto_library")


proto_library(
    name = "proto",
    srcs = glob(["*.proto"]),
    visibility = ["//visibility:public"],
    deps = [
        "@com_google_protobuf//:descriptor_proto",
    ]
)

cc_proto_library(
    name = "proto_lib",
    visibility = ["//visibility:public"],
    deps = [":proto"]
)