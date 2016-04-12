#ifndef _IReplyEncoder_h_
#define _IReplyEncoder_h_

#include "cps_serverbase_shared.h"

namespace Cps {

struct ConnectionData;
struct RequestData;

class CPS_SERVERBASE_SHARED IReplyEncoder
{
public:
    IReplyEncoder();
    virtual ConnectionData encode(const RequestData *data) const = 0;
    virtual ~IReplyEncoder() = 0;

private:
    DECLARE_INDIVIDUAL(IReplyEncoder)
};

} // namespace Cps

#endif // _IReplyEncoder_h_
