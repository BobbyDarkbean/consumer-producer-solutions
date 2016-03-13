#ifndef _ConnectionTask_h_
#define _ConnectionTask_h_

#include "itask.h"
#include "cps_server_shared.h"

namespace Cps {

struct ConnectionInfo;

struct ConnectionTaskImplementation;
class CPS_SERVER_SHARED ConnectionTask : public ITask
{
public:
    ConnectionTask();

    ConnectionInfo info() const;
    void setInfo(const ConnectionInfo &);

    void run() = 0;

    ~ConnectionTask();

private:
    DECLARE_INDIVIDUAL(ConnectionTask)
    DECLARE_UNIQUE_IMPLEMENTATION(ConnectionTask)
};

} // namespace Cps

#endif // _ConnectionTask_h_
