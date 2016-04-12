#ifndef _ISocketController_h_
#define _ISocketController_h_

#include "cps_serverbase_shared.h"

namespace Cps {

struct ConnectionData;

class CPS_SERVERBASE_SHARED ISocketController
{
public:
    ISocketController();

    virtual bool isReadyToRead() const = 0;
    virtual ConnectionData read() = 0;
    virtual void write(const ConnectionData &) = 0;

    virtual ~ISocketController() = 0;

private:
    DECLARE_INDIVIDUAL(ISocketController)
};

} // namespace Cps

#endif // _ISocketController_h_
