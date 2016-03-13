#ifndef _Producer_h_
#define _Producer_h_

#include "irunnable.h"

namespace Cps {

class ITaskCreator;
class ITaskQueue;

class ProducerImplementation;
class CPS_KERNEL_SHARED Producer : public IRunnable
{
public:
    Producer();

    ITaskQueue *queue() const;
    void setQueue(ITaskQueue *);

    virtual ITaskCreator *creator() const = 0;

    ~Producer();

private:
    DECLARE_INDIVIDUAL(Producer)
    DECLARE_UNIQUE_IMPLEMENTATION(Producer)
};

} // namespace Cps

#endif // _Producer_h_
