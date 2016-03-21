#include "ireplyencoder.h"

namespace Cps {

IReplyEncoder::IReplyEncoder()
{
    // no-op
}

std::string IReplyEncoder::encode(const RequestData * /* data */) const
{
    return std::string();
}

IReplyEncoder::~IReplyEncoder()
{
    // no-op
}

} // namespace Cps
