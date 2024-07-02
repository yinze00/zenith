#pragma once

#include "proto/zenith.pb.h"

#include <brpc/server.h>
#include <butil/logging.h>
#include <gflags/gflags.h>
#include <json2pb/pb_to_json.h>
#include <memory>

#include "nexus/turing/core/graph_service_impl.hh"
#include "zenith_biz.hh"

namespace zenith {

nexus::turing::GraphRequest *ToGraphRequest(const recall::ZenithRequest *req);

class ZenithServiceImpl : public recall::ZenithService,
                          public nexus::turing::GraphServiceImpl {

public:
  ZenithServiceImpl();
  virtual ~ZenithServiceImpl() = default;

  virtual void Recall(google::protobuf::RpcController *cntl_base,
                      const recall::ZenithRequest *req,
                      recall::ZenithResponse *rsp,
                      google::protobuf::Closure *done);

  nexus::turing::GraphBizPtr init_biz() override;

private:
  // Bizptr biz_{nullptr};
};
} // namespace zenith