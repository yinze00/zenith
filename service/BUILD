cc_library(
    name = "zenith_service", 
    hdrs = glob(["*.hh"]),
    srcs = glob(["*.cc"]),
    visibility = ["//visibility:public"],
    deps = [
        "@brpc",
        "@nexus//nexus/turing/core",
        "@nexus//nexus/cc/kernel:ann_kernel",
        "@nexus//nexus/cc:ops",
        "//proto:proto_lib"
    ]
)