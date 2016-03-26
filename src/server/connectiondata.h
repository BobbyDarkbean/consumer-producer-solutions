#ifndef _ConnectionData_h_
#define _ConnectionData_h_

#include <string>

namespace Cps {

struct ConnectionData
{
    int socketId;
    std::string rawBytes;
};

} // namespace Cps

#endif //_ConnectionData_h_
