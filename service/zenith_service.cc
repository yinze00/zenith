
#include "zenith_service.hh"
#include "tensorflow/core/framework/tensor.h"
#include "zenith_biz.hh"
#include "zenith_turing_closure.hh"
#include <memory>

#include "nexus/turing/common/const_defs.hh"

namespace zenith {

nexus::turing::GraphRequest *ToGraphRequest(const recall::ZenithRequest *req) {

  auto graph_request = new nexus::turing::GraphRequest();

  graph_request->set_biz(req->biz());

  auto graph_info = graph_request->mutable_graph_info();

  graph_info->add_fetches()->assign("ResultConstructOp:0");
  graph_info->add_fetches()->assign("ResultConstructOp:1");

  graph_info->add_targets()->assign(nexus::common::KGRAPH_DONE);

  tensorflow::Tensor emb(
      tensorflow::DT_FLOAT,
      tensorflow::TensorShape({static_cast<int64_t>(req->query_emb_size())}));

  auto flat = emb.flat<float>();
  std::copy(req->query_emb().begin(), req->query_emb().end(), flat.data());

  auto in = graph_info->add_inputs();

  *in->mutable_name() = "user_emb";
  // in->mutable_tensor()
  emb.AsProtoTensorContent(in->mutable_tensor());

  auto in_topk = graph_info->add_inputs();
  *in_topk->mutable_name() = "topk";
  in_topk->mutable_tensor()->add_uint32_val(req->topk());
  in_topk->mutable_tensor()->set_dtype(::tensorflow::DT_UINT32);

  return graph_request;
}

ZenithServiceImpl::ZenithServiceImpl() {}

nexus::turing::GraphBizPtr ZenithServiceImpl::init_biz() {
  nexus::turing::GraphBizPtr biz;

  biz.reset(new ZenithBiz());
  return biz;
}

void ZenithServiceImpl::Recall(google::protobuf::RpcController *cntl_base,
                               const recall::ZenithRequest *req,
                               recall::ZenithResponse *rsp,
                               google::protobuf::Closure *done) {

  rsp->set_message("Hello From Server.");

  auto graph_request = ToGraphRequest(req);
  auto graph_response = new nexus::turing::GraphResponse();

  auto closure =
      new ZenithTuringClosure(graph_request, graph_response, rsp, done);

  runGraph(cntl_base, graph_request, graph_response, closure);

  // done->Run();
}

} // namespace zenith