#include "connectiondata.h"
#include "requestdata.h"

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
    connectionData.rawBytes.push_back(data->type + '0');

    return connectionData;
}

MockReplyEncoder::~MockReplyEncoder()
{
}

} // namespace Cps
