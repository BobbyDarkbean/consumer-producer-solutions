#ifndef _IReplyEncoder_h_
#define _IReplyEncoder_h_

#include <string>
#include "cps_server_shared.h"

namespace Cps {

struct RequestData;

class CPS_SERVER_SHARED IReplyEncoder
{
public:
    IReplyEncoder();
    virtual std::string encode(const RequestData *data) const = 0;
    virtual ~IReplyEncoder() = 0;

private:
    DECLARE_INDIVIDUAL(IReplyEncoder)
};

} // namespace Cps

#endif // _IReplyEncoder_h_
