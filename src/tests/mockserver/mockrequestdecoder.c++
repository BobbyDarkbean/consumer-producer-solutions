#include "connectiondata.h"
#include "requestdata.h"

#include "mockrequestdecoder.h"

namespace Cps {

MockRequestDecoder::MockRequestDecoder()
    : IRequestDecoder()
{
}

RequestData *MockRequestDecoder::decode(const ConnectionData &data) const
{
    RequestData *requestData = new RequestData;

    requestData->socketId = data.socketId;
    requestData->request = data.rawBytes;
    char meta = *data.rawBytes.begin();

    if (isdigit(meta))
        requestData->type = meta - '0';
    else
        requestData->type = -1;

    return requestData;
}

MockRequestDecoder::~MockRequestDecoder()
{
}

} // namespace Cps
