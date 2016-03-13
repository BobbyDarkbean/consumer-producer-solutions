#ifndef _TaskCreator_h_
#define _TaskCreator_h_

#include "cps_kernel_shared.h"

namespace Cps {

class ITask;
class TaskFactory;

class TaskCreatorImplementation;
class CPS_KERNEL_SHARED TaskCreator
{
public:
    TaskCreator();

    ITask *createTask(int type) const;

    bool hasFactory(int type) const;
    void insertFactory(int type, TaskFactory *factory);
    void removeFactory(int type);

    ~TaskCreator();

private:
    DECLARE_INDIVIDUAL(TaskCreator)
    DECLARE_IMPLEMENTATION(TaskCreator)
};

} // namespace Cps

#endif // _TaskCreator_h_
