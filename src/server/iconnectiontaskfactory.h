#ifndef _IConnectionTaskFactory_h_
#define _IConnectionTaskFactory_h_

#include "itaskfactory.h"
#include "connectiontask.h"
#include "cps_server_shared.h"

namespace Cps {

class CPS_SERVER_SHARED IConnectionTaskFactory : public ITaskFactory
{
public:
    IConnectionTaskFactory();
    ConnectionTask *create() const = 0;
    ~IConnectionTaskFactory();

private:
    DECLARE_INDIVIDUAL(IConnectionTaskFactory)
};

} // namespace Cps

#endif // _IConnectionTaskFactory_h_
