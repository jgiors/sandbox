#include <iostream>

using std::cout;

#define VERBOSE_ENABLED(X)  (X)
#define VERBOSE_DISABLED(...)

int main(int argc, char* argv[])
{
    int answer = 42;
    VERBOSE_ENABLED(cout << "\nHowdy! The answer is " << answer << ". I kid you not.\n\n");
    VERBOSE_DISABLED(cout << "*** THIS SHOULD NOT PRINT, NOT EVEN THE ANSWER " << answer << " ***\n\n");
    return 0;
}
