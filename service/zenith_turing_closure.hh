#pragma once

#include "nexus/turing/core/graph_closure.hh"
#include "nexus/turing/proto/run_graph.pb.h"

// #include <xbyak/xbyak.h>
#include "proto/zenith.pb.h"

namespace zenith {

using nexus::turing::GraphRequest;
using nexus::turing::GraphResponse;

// using ZenithTuringClosure =
//     typename nexus::turing::GraphClosure<recall::ZenithResponse>;

class ZenithTuringClosure : public nexus::turing::GraphClosure {
public:
  ZenithTuringClosure(GraphRequest *graph_req, GraphResponse *graph_rsp,
                      recall::ZenithResponse *response,
                      google::protobuf::Closure *done)
      : nexus::turing::GraphClosure(graph_req, graph_rsp, (void *)response,
                                    done) {}
  void fill_rsp() override {

    auto rsp = static_cast<recall::ZenithResponse *>(rsp_);

    for (auto &nt : ursp_->outputs()) {
      tensorflow::Tensor tensor;
      tensor.FromProto(nt.tensor());
      LOG(INFO) << nt.name() << " " << tensor.DebugString(100);

      float *l = tensor.flat<float>().data();
      size_t len = tensor.flat<float>().size();

      // TODO: config the head by json params
      if (nt.name() == "recall_results") {
        rsp->mutable_sims()->Assign(l, l + len);
      }
    }
  }
};

} // namespace zenith