# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

workspace(name = "zenith")


load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")


############################################### bazel commons ###############################################
git_repository(
    name = "rules_proto",
    commit = "cfdc2fa31879c0aebe31ce7702b1a9c8a4be02d2",
    remote = "https://github.com/bazelbuild/rules_proto.git",
)
############################################### bazel commons ###############################################

###############################################  commons ###############################################
git_repository(
    name = "yaml-cpp",
    tag  = "yaml-cpp-0.7.0",
    remote = "https://github.com/jbeder/yaml-cpp.git",
)
###############################################  commons ###############################################


############################################### apache_brpc ###############################################
load("//third_party/brpc:brpc_workspace.bzl", "brpc_workspace")
brpc_workspace();
############################################### apache_brpc ###############################################

# ############################################### org_tensorflow ###############################################

new_local_repository(
    name = "org_tensorflow",
    path = "/home/yinze/dev/zenith-turing/tensorflow-plus",
    build_file = "/home/yinze/dev/zenith-turing/tensorflow-plus/BUILD",
)

http_archive(
    name = "io_bazel_rules_closure",
    sha256 = "ddce3b3a3909f99b28b25071c40b7fec7e2e1d1d1a4b2e933f3082aa99517105",
    strip_prefix = "rules_closure-316e6133888bfc39fb860a4f1a31cfcbae485aef",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_closure/archive/316e6133888bfc39fb860a4f1a31cfcbae485aef.tar.gz",
        "https://github.com/bazelbuild/rules_closure/archive/316e6133888bfc39fb860a4f1a31cfcbae485aef.tar.gz",  # 2019-03-21
    ],
)

# http_archive(
#     name = "bazel_skylib",
#     sha256 = "2c62d8cd4ab1e65c08647eb4afe38f51591f43f7f0885e7769832fa137633dcb",
#     strip_prefix = "bazel-skylib-0.7.0",
#     urls = ["https://github.com/bazelbuild/bazel-skylib/archive/0.7.0.tar.gz"],
# )


load("@org_tensorflow//third_party:repo.bzl", "tf_http_archive")
load("@org_tensorflow//tensorflow:workspace.bzl", "tf_workspace")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

tf_workspace(path_prefix = "", tf_repo_name = "org_tensorflow")
# ############################################### org_tensorflow ###############################################


############################################### nexus ###############################################
new_local_repository(
    name = "nexus",
    path = "/home/yinze/dev/zenith/nexus",
    build_file = "/home/yinze/dev/zenith/nexus/BUILD",
)
############################################### nexus ###############################################