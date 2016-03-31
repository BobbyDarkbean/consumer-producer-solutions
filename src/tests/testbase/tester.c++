#include <ostream>
#include "tester.h"

namespace Cps {

struct TesterImplementation
{
    TesterImplementation();

    void echo(const char *msg);
    void printSummary();

    bool pass(const char *func);
    bool fail(const char *func, const char *file, long line);

    ~TesterImplementation();

    unsigned passed;
    unsigned failed;
    std::ostream *log;
};

TesterImplementation::TesterImplementation()
    : passed(0),
      failed(0),
      log(nullptr)
{
}

void TesterImplementation::echo(const char *msg)
{
    *log << msg << '\n';
}

void TesterImplementation::printSummary()
{
    *log << "Summary : " << passed << " passed, " << failed << " failed.\n";
}

bool TesterImplementation::pass(const char *func)
{
    *log << "PASS\t: " << func << '\n';
    ++passed;
    return true;
}

bool TesterImplementation::fail(const char *func, const char *file, long line)
{
    *log << "FAIL\t: " << func << " at " << file << '(' << line << ')' << '\n';
    ++failed;
    return false;
}

TesterImplementation::~TesterImplementation()
{
    if (log)
        printSummary();
}

Tester::Tester()
    : m(new TesterImplementation)
{
}

std::ostream *Tester::log() const
{
    return m->log;
}

void Tester::setLog(std::ostream *log)
{
    m->log = log;
}

void Tester::echo(const char *msg)
{
    m->echo(msg);
}

unsigned Tester::passed() const
{
    return m->passed;
}

unsigned Tester::failed() const
{
    return m->failed;
}

bool Tester::verify(bool expr, const char *func, const char *file, long line)
{
    return expr ? m->pass(func) : m->fail(func, file, line);
}

Tester::~Tester()
{
    delete m;
}

} // namespace Cps
