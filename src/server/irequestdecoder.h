#ifndef _IRequestDecoder_h_
#define _IRequestDecoder_h_

#include <string>
#include "cps_server_shared.h"

namespace Cps {

struct RequestData;

class CPS_SERVER_SHARED IRequestDecoder
{
public:
    IRequestDecoder();
    virtual RequestData *decode(const std::string &request) const = 0;
    virtual ~IRequestDecoder() = 0;

private:
    DECLARE_INDIVIDUAL(IRequestDecoder)
};

} // namespace Cps

#endif // _IRequestDecoder_h_
