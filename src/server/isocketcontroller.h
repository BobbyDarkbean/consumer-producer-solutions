#ifndef _ISocketController_h_
#define _ISocketController_h_

#include <string>
#include "cps_server_shared.h"

namespace Cps {

class CPS_SERVER_SHARED ISocketController
{
public:
    ISocketController();

    virtual bool isReadyToRead() const = 0;
    virtual void read(std::string &request) = 0;
    virtual void write(const std::string &reply) = 0;

    virtual ~ISocketController() = 0;

private:
    DECLARE_INDIVIDUAL(ISocketController)
};

} // namespace Cps

#endif // _ISocketController_h_
