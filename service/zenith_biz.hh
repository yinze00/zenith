#pragma once

#include "nexus/turing/common/op_util.hh"
#include "nexus/turing/core/graph_biz.hh"

#include <cstdint>
#include <memory>

namespace zenith {

class ZenithBiz : public nexus::turing::GraphBiz {
public:
  ZenithBiz() = default;
  virtual ~ZenithBiz() = default;

protected:
  tensorflow::SessionResourcePtr createSessionResource(uint32_t count) override;
  // tensorflow::QueryResourcePtr createQueryResource() override;
};

using ZenithBizPtr = std::shared_ptr<ZenithBiz>;

} // namespace zenith