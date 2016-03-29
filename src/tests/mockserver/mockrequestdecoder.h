#ifndef _MockRequestDecoder_h_
#define _MockRequestDecoder_h_

#include "irequestdecoder.h"

namespace Cps {

class MockRequestDecoder : public IRequestDecoder
{
public:
    MockRequestDecoder();
    RequestData *decode(const ConnectionData &data) const;
    ~MockRequestDecoder();

private:
    DECLARE_INDIVIDUAL(MockRequestDecoder)
};

} // namespace Cps

#endif // _MockRequestDecoder_h_
