#include <Windows.h>
#include <iostream>
#include <tuple>
#include <utility>

template <typename... T>
struct TuplePrinter
{
    std::tuple<T...> _tuple;
    TuplePrinter(T... args) : _tuple(args...) {}

    template<int N>
    void print()
    {
        print<N - 1>();
        std::cout << std::get<N - 1>(_tuple) << std::endl;
    }

    template<>
    void print<0>() {}

    void print() { print<std::tuple_size<std::tuple<T...>>::value>(); }
};

int main(int argc, char* argv[])
{
    TuplePrinter<std::string, int, std::string> tp( "Hi", 42, "Duh!" );
    tp.print();
    return 0;
}
