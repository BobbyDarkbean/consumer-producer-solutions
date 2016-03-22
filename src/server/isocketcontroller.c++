#include "isocketcontroller.h"

namespace Cps {

ISocketController::ISocketController()
{
    // no-op
}

bool ISocketController::isReadyToRead() const
{
    return false;
}

void ISocketController::read(std::string & /* request */)
{
    // no-op
}

void ISocketController::write(const std::string & /* reply */)
{
    // no-op
}

ISocketController::~ISocketController()
{
    // no-op
}

} // namespace Cps
