#include "isocketcontroller.h"
#include "connectiondata.h"

namespace Cps {

ISocketController::ISocketController()
{
    // no-op
}

bool ISocketController::isReadyToRead() const
{
    return false;
}

ConnectionData ISocketController::read()
{
    return ConnectionData();
}

void ISocketController::write(const ConnectionData &)
{
    // no-op
}

ISocketController::~ISocketController()
{
    // no-op
}

} // namespace Cps
