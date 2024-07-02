#!/bin/bash

bazelisk build //:zenith_server --incompatible_struct_has_no_methods --config=lld --color=auto

# ln -sf bazel-zenith/external 

# bazelisk build :zenith_server \
#     --incompatible_struct_has_no_methods --config=lld --color=auto \
#     --override_repository=bazel_vscode_compdb=/home/yinze/.vscode-server/extensions/galexite.bazel-cpp-tools-1.0.5/compdb/ --aspects=@bazel_vscode_compdb//:aspects.bzl%compilation_database_aspect --color=no --show_result=2147483647 --noshow_progress --noshow_loading_progress --output_groups=compdb_files,header_files --build_event_json_file=/tmp/tmp-45383-nzD6gqya2Nxv --action_env=BAZEL_CPP_TOOLS_TIMESTAMP=1719403741.126 && /home/yinze/.vscode-server/extensions/galexite.bazel-cpp-tools-1.0.5/compdb/postprocess.py -s -b /tmp/tmp-45383-nzD6gqya2Nxv && rm /tmp/tmp-45383-nzD6gqya2Nxv