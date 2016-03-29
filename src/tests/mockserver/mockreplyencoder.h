#ifndef _MockReplyEncoder_h_
#define _MockReplyEncoder_h_

#include "ireplyencoder.h"

namespace Cps {

class MockReplyEncoder : public IReplyEncoder
{
public:
    MockReplyEncoder();
    ConnectionData encode(const RequestData *data) const;
    ~MockReplyEncoder();

private:
    DECLARE_INDIVIDUAL(MockReplyEncoder)
};

} // namespace Cps

#endif // _MockReplyEncoder_h_
