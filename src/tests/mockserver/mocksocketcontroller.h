#ifndef _MockSocketController_h_
#define _MockSocketController_h_

#include "isocketcontroller.h"

namespace Cps {

class MockLogicFacade;

struct MockSocketControllerImplementation;
class MockSocketController : public ISocketController
{
public:
    explicit MockSocketController(MockLogicFacade *);

    bool isReadyToRead() const;
    ConnectionData read();
    void write(const ConnectionData &);

    ~MockSocketController();

private:
    DECLARE_INDIVIDUAL(MockSocketController)
    DECLARE_UNIQUE_IMPLEMENTATION(MockSocketController)
};

} // namespace Cps

#endif // _MockSocketController_h_
