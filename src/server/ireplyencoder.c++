#include "ireplyencoder.h"
#include "connectiondata.h"

namespace Cps {

IReplyEncoder::IReplyEncoder()
{
    // no-op
}

ConnectionData IReplyEncoder::encode(const RequestData * /* data */) const
{
    return ConnectionData();
}

IReplyEncoder::~IReplyEncoder()
{
    // no-op
}

} // namespace Cps
