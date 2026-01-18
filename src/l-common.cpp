// The List series of exercises l1, l2, ... explores more algorithmic examples.
// Because of that, i've decided to explore some more complicated Cpp features
// and add some utilities in this common C++ file, as well as using test asserts
// for all algorithms looking for edge cases.

// Since each exercise is compiled individually manually from clang, we can
// use a cpp directly as an #include as we are guarenteed to never include it
// more than once, instead of complicating the build script with headers and
// includes. Just in case, though:
#pragma once
// ;)

#include <iostream>
#include <algorithm>
#include <string_view>
#include <span>
#include <stdexcept>

// Templates are like generics in Rust, except more powerful and less
// expressive.
template <typename T>
inline std::string sprint_span(
    // A span is sort of like a slice in rust.
    // Spans are only available in C++20 or later.
    std::span<const T> span
) {
    std::string output;

    output.append("{");

    // There's quite a few things going on in the following for loop:

    // 1. Iteration
    // In C++ you can iterate over a span with
    //     for (const auto& item : span) { ... }
    // This is equivalent to
    //     for item in span { ... }
    // in rust.

    // 2. const auto&
    // In C++ types go before the name so we must put something as our type.
    // Like in rust, most of the time the type is obvious, so we don't bother.
    // The `auto` keyword deduces this type, or covers some absurdly large
    // compound generic type, i.e. a<b<c<int>>>.
    //
    // auto& means that it is a reference, which is an immutable non-null
    // pointer. Basically a read only pointer which comes from the iteration
    // of span.

    // 3. Enumeration
    // To enumerate over the iteration, add
    //     int i = 0;
    // before the iteration expression. CRUCIALLY, we are not iterating i in
    // this for loop declaration. Thus, i must be iterated at the end of the
    // for loop.

    for (int i = 0; const auto& t : span) {
        output.append(std::format("{}", t));
        if (i < span.size() - 1) output.append(", ");
        i++;
    }
    output.append("}");

    return output;
}

template <typename T>
inline void assert_spans(
    std::span<const T> test,
    std::span<const T> truth,
    std::string_view name
) {
    if (!std::ranges::equal(test, truth)) {
        std::cerr << "\nTest '" << name << "' failed!\n";
        std::cerr << "Test:  " ;
        std::cerr << sprint_span(test);
        std::cerr << "\n";
        std::cerr << "Truth: " ;
        std::cerr << sprint_span(truth);
        std::cerr << "\n\n";

        throw std::runtime_error("Assert failed");
    } else {
        std::cout << "Test '" << name << "' passed!\n";
    }
}

// This is an override of assert_spans to make it easier to just pass arrays.
// It's syntactic sugar, but because of limitations of C++ templates, often the
// type will have to be manually specified by the caller:
//     assert_spans<int>( ... )
template <typename T>
inline void assert_spans(
    std::span<const T> test,
    std::initializer_list<const T> truth,
    std::string_view msg
) {
    assert_spans(test, std::span<const T>{truth}, msg);
}


template <typename T>
inline void assert_one(
    T test,
    T truth,
    std::string_view name
) {
    if (test != truth) {
        std::cerr << "\nTest '" << name << "' failed!\n";
        std::cerr << "Test:  " << test << "\n";
        std::cerr << "Truth: " << truth << "\n\n";

        throw std::runtime_error("Assert failed");
    } else {
        std::cout << "Test '" << name << "' passed!\n";
    }
}
