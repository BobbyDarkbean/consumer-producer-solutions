#ifndef _TaskCreator_h_
#define _TaskCreator_h_

#include "consprod_kernel_shared.h"

namespace ConsProd {

class ITask;
class TaskFactory;

class TaskCreatorImplementation;
class CONSPROD_KERNEL_SHARED TaskCreator
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

} // namespace ConsProd

#endif // _TaskCreator_h_
