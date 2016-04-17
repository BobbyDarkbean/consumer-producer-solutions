#include "connectiondata.h"
#include "requestdata.h"
#include "maintenancetask.h"

#include "mockreplyencoder.h"

namespace Cps {

MockReplyEncoder::MockReplyEncoder()
    : IReplyEncoder()
{
}

ConnectionData MockReplyEncoder::encode(const RequestData *data) const
{
    ConnectionData connectionData;

    connectionData.socketId = data->socketId;
    connectionData.rawBytes = data->type == MaintenanceTask_StopServer
            ? "stop"
            : std::to_string(data->type);

    return connectionData;
}

MockReplyEncoder::~MockReplyEncoder()
{
}

} // namespace Cps
