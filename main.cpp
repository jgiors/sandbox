#include <iostream>

using std::cerr;

#define VERBOSE_ENABLED(X)  (X)
#define VERBOSE_DISABLED(...)

class Logger {
public:
    template <typename T>
    Logger& operator<<(T x)
    {
        cerr << x;
        return *this;
    }
};

Logger logger;

int main(int argc, char* argv[])
{
    int answer = 42;
    VERBOSE_ENABLED(logger << "\nHowdy! The answer is " << answer << ". I kid you not.\n\n");
    VERBOSE_DISABLED(logger << "*** THIS SHOULD NOT PRINT, NOT EVEN THE ANSWER " << answer << " ***\n\n");
    return 0;
}
