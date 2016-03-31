#ifndef _Tester_h_
#define _Tester_h_

#include <iosfwd>
#include "cps_testbase_shared.h"

namespace Cps {

struct TesterImplementation;
class CPS_TESTBASE_SHARED Tester
{
public:
    Tester();

    std::ostream *log() const;
    void setLog(std::ostream *);

    void echo(const char *msg);

    unsigned passed() const;
    unsigned failed() const;

    bool verify(bool expr, const char *func, const char *file, long line);

    template <typename T>
    bool compare(T actual, T expected, const char *func, const char *file, long line)
    {
        return verify(actual == expected, func, file, line);
    }

    ~Tester();

private:
    DECLARE_INDIVIDUAL(Tester)
    DECLARE_IMPLEMENTATION(Tester)
};

} // namespace Cps

#define VERIFY(expr, func) \
    tester()->verify(expr, func, __FILE__, __LINE__)

#define COMPARE(actual, expected, func) \
    tester()->compare(actual, expected, func, __FILE__, __LINE__)

#define BEGIN_TEST(name) \
    tester()->echo(" ------- [" #name "] -------")

#define END_TEST(name) \
    tester()->echo(" ------- [" #name "] -------\n")

#define PRINT_RETURN(code) \
    tester()->echo("Work loop return code: " + code)

#endif // _Tester_h_
