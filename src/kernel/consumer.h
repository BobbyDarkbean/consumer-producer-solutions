#ifndef _Consumer_h_
#define _Consumer_h_

#include "irunnable.h"

namespace Cps {

class ITaskQueue;

class ConsumerImplementation;
class CPS_KERNEL_SHARED Consumer : public IRunnable
{
public:
    Consumer();

    ITaskQueue *queue() const;
    void setQueue(ITaskQueue *);

    ~Consumer();

private:
    DECLARE_INDIVIDUAL(Consumer)
    DECLARE_UNIQUE_IMPLEMENTATION(Consumer)
};

} // namespace Cps

#endif // _Consumer_h_
