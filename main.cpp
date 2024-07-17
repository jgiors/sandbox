#include <Windows.h>
#include <iostream>
#include <tuple>
#include <utility>

/*
template <typename... T>
struct TupleContainer
{
    std::tuple<T...> _tuple;
    TupleContainer(T... args) : _tuple(args...) {}
};

template <typename T, typename... Args>
void PrintTuple(T t, Args... args)
{
    cout << t;
    PrintTuple(args...);
}
*/

auto _tuple{std::make_tuple( "Hi", 42 )};

template<int N>
void printTuple()
{
    if (N < std::tuple_size<decltype(_tuple)>::value)
    {
        std::cout << std::get<N>(_tuple);
        printTuple<N + 1>();
    }
}

template <>
void printTuple<2>()
{
}

int main(int argc, char* argv[])
{
//    TupleContainer<std::string, int> container{ "Hi", 42 };
//    std::apply(PrintTuple, container._tuple);
    printTuple<0>();
    return 0;
}
