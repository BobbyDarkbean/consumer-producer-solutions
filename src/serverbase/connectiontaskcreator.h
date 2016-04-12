#ifndef _ConnectionTaskCreator_h_
#define _ConnectionTaskCreator_h_

#include "itaskcreator.h"
#include "connectiontask.h"
#include "cps_serverbase_shared.h"

namespace Cps {

class IConnectionTaskFactory;

struct ConnectionTaskCreatorImplementation;
class CPS_SERVERBASE_SHARED ConnectionTaskCreator : public ITaskCreator
{
public:
    ConnectionTaskCreator();

    ConnectionTask *createTask(int type) const;

    bool hasFactory(int type) const;
    void insertFactory(int type, IConnectionTaskFactory *factory);
    void removeFactory(int type);

    ~ConnectionTaskCreator();

private:
    DECLARE_INDIVIDUAL(ConnectionTaskCreator)
    DECLARE_IMPLEMENTATION(ConnectionTaskCreator)
};

} // namespace Cps

#endif // _ConnectionTaskCreator_h_
