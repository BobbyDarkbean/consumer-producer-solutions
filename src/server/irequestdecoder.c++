#include "irequestdecoder.h"

namespace Cps {

IRequestDecoder::IRequestDecoder()
{
    // no-op
}

RequestData *IRequestDecoder::decode(const ConnectionData & /* data */) const
{
    return nullptr;
}

IRequestDecoder::~IRequestDecoder()
{
    // no-op
}

} // namespace Cps
