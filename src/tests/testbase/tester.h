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
    template <typename T>
    void echo(const char *key, T value);

    unsigned passed() const;
    unsigned failed() const;

    bool verify(bool expr, const char *func, const char *file, long line);

    template <typename T>
    bool compare(T actual, T expected, const char *func, const char *file, long line)
    {
        return verify(actual == expected, func, file, line);
    }

    void writeToLog(const char *);
    void writeToLog(char);
    void writeToLog(int);

    ~Tester();

private:
    DECLARE_INDIVIDUAL(Tester)
    DECLARE_IMPLEMENTATION(Tester)
};

template <typename T>
inline Tester &operator <<(Tester &tester, T t)
{ tester.writeToLog(t); return tester; }

template <typename T>
inline void Tester::echo(const char *key, T value)
{ *this << key << ": " << value << '\n'; }

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
    (*tester()) << '\n' << "Return code: " << code << '\n'

#endif // _Tester_h_
