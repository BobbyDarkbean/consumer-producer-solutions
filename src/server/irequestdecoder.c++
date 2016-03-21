#include "irequestdecoder.h"

namespace Cps {

IRequestDecoder::IRequestDecoder()
{
    // no-op
}

RequestData *IRequestDecoder::decode(const std::string & /* request */) const
{
    return nullptr;
}

IRequestDecoder::~IRequestDecoder()
{
    // no-op
}

} // namespace Cps
