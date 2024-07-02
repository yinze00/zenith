#include "zenith_biz.hh"
#include <cstdint>
namespace zenith {

tensorflow::SessionResourcePtr
ZenithBiz::createSessionResource(uint32_t count) {
  return nexus::turing::GraphBiz::createSessionResource(count);
}

} // namespace zenith