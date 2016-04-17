#include <locale>
#include "connectiondata.h"
#include "requestdata.h"
#include "maintenancetask.h"

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
    char meta = !data.rawBytes.empty() ? *data.rawBytes.begin() : '-';
    requestData->type = std::isdigit(meta, std::locale())
            ? std::stoi(data.rawBytes)
            : MaintenanceTask_StopServer;

    return requestData;
}

MockRequestDecoder::~MockRequestDecoder()
{
}

} // namespace Cps
