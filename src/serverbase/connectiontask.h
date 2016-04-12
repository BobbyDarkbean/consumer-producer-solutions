#ifndef _ConnectionTask_h_
#define _ConnectionTask_h_

#include "itask.h"
#include "cps_serverbase_shared.h"

namespace Cps {

struct RequestData;

struct ConnectionTaskImplementation;
class CPS_SERVERBASE_SHARED ConnectionTask : public ITask
{
public:
    ConnectionTask();

    RequestData *data() const;
    void setData(RequestData *);

    ~ConnectionTask();

private:
    DECLARE_INDIVIDUAL(ConnectionTask)
    DECLARE_UNIQUE_IMPLEMENTATION(ConnectionTask)
};

} // namespace Cps

#endif // _ConnectionTask_h_
