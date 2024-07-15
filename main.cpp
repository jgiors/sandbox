#include <Windows.h>
#include <sstream>
#include <iostream>

using std::cerr;

#define VERBOSE_ENABLED(X)  (X)
#define VERBOSE_DISABLED(...)

class Logger {
public:
    template <typename T>
    Logger& operator<<(const T &x)
    {
        std::ostringstream s;
        s << x;
        cerr << s.str();
        OutputDebugString(s.str().c_str());
        return *this;
    }
};

Logger Log;

int main(int argc, char* argv[])
{
    int answer = 42;
    VERBOSE_ENABLED(Log << "\nHowdy! The answer is " << answer << ". I kid you not.\n\n");
    VERBOSE_DISABLED(Log << "*** THIS SHOULD NOT PRINT, NOT EVEN THE ANSWER " << answer << " ***\n\n");
    return 0;
}
