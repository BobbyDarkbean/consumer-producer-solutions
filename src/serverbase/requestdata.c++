#include "requestdata.h"

namespace Cps {

RequestData::RequestData()
    : socketId(-1),
      type(-1),
      request(),
      reply(),
      state(RequestState_Undefined)
{
}

} // namespace Cps
