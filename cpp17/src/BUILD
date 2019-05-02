cc_binary(
    name = "futures",
    srcs = ["futures.cc"],
    copts = ["--std=c++17"],
    linkopts = ["-pthread"],
    visibility = ["//cpp17/src:__pkg__"],
)

cc_binary(
    name = "stl",
    srcs = ["stl.cc", "util.h"],
    copts = ["--std=c++17"],
    visibility = ["//cpp17/src:__pkg__"],
)
