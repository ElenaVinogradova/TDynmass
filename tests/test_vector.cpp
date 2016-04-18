#define CATCH_CONFIG_MAIN
#include "vector.h"
#include "catch.hpp"

template <class T>
void cmp_array(const Vector<T> &rhs, const T *expected, const std::size_t N) {
        REQUIRE(rhs.size() == N);
    for(std::size_t i = 0; i < N; ++i) {
        REQUIRE(rhs[i] == expected[i]);
    }
}

TEST_CASE("Vector default ctor") {
    SECTION("int") {
        Vector<int> v;
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == 0);
    }
    SECTION("double") {
        Vector<double> v;
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == 0);
    }
    SECTION("char") {
        Vector<char> v;
        REQUIRE(v.size() == 0);
        REQUIRE(v.capacity() == 0);
    }
}

TEST_CASE("Vector explicit init ctor") {
    SECTION("int") {
        REQUIRE(Vector<int>{6}.size() == 6);
    }
    SECTION("double") {
        REQUIRE(Vector<double>{6}.size() == 6);
    }
    SECTION("char") {
        REQUIRE(Vector<char>{6}.size() == 6);
    }
}

TEST_CASE("Vector init ctor") {
    SECTION("int") {
        Vector<int> v(6, 6);
        int expected[] = {6, 6, 6, 6, 6, 6};
        REQUIRE(v.size() == 6);
        cmp_array(v, expected, 6);
    }
    SECTION("double") {
        Vector<double> v{6, 6.1};
        double expected[] = {6.1, 6.1, 6.1, 6.1, 6.1, 6.1};
        REQUIRE(v.size() == 6);
        cmp_array(v, expected, 6);
    }
    SECTION("char") {
        Vector<char> v{6, 'h'};
        char expected[] = {'h', 'h', 'h', 'h', 'h', 'h'};
        REQUIRE(v.size() == 6);
        cmp_array(v, expected, 6);
    }
}

TEST_CASE("Copy ctor") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0};
        v[0] = 100;
        v[1] = -1;
        v[2] = 0;
        Vector<int> w{v};
        cmp_array(w, expected, 3);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        v[0] = 100.123;
        v[1] = -1.01;
        v[2] = 0.0;
        Vector<double> w{v};
        cmp_array(w, expected, 3);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        v[0] = 'h';
        v[1] = '2';
        v[2] = '+';
        Vector<char> w{v};
        cmp_array(w, expected, 3);
    }
}

TEST_CASE("Assigment ctor") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0};
        v[0] = 100;
        v[1] = -1;
        v[2] = 0;
        Vector<int> w(std::move(v));
        cmp_array(w, expected, 3);
        REQUIRE(v.size() == 0);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        v[0] = 100.123;
        v[1] = -1.01;
        v[2] = 0.0;
        Vector<double> w(std::move(v));
        cmp_array(w, expected, 3);
        REQUIRE(v.size() == 0);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        v[0] = 'h';
        v[1] = '2';
        v[2] = '+';
        Vector<char> w(std::move(v));
        cmp_array(w, expected, 3);
        REQUIRE(v.size() == 0);
    }
}

TEST_CASE("Copy assigment") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0};
        v[0] = 100;
        v[1] = -1;
        v[2] = 0;
        Vector<int> w = v;
        cmp_array(w, expected, 3);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        v[0] = 100.123;
        v[1] = -1.01;
        v[2] = 0.0;
        Vector<double> w = v;
        cmp_array(w, expected, 3);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        v[0] = 'h';
        v[1] = '2';
        v[2] = '+';
        Vector<char> w = v;
        cmp_array(w, expected, 3);
    }
}

TEST_CASE("Assigment") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0};
        v[0] = 100;
        v[1] = -1;
        v[2] = 0;
        Vector<int> w = std::move(v);
        cmp_array(w, expected, 3);
        REQUIRE(v.size() == 0);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        v[0] = 100.123;
        v[1] = -1.01;
        v[2] = 0.0;
        Vector<double> w = std::move(v);
        cmp_array(w, expected, 3);
        REQUIRE(v.size() == 0);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        v[0] = 'h';
        v[1] = '2';
        v[2] = '+';
        Vector<char> w = std::move(v);
        cmp_array(w, expected, 3);
        REQUIRE(v.size() == 0);
    }
}

TEST_CASE("Indxing operator") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0};
        for(std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        cmp_array(v, expected, 3);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        cmp_array(v, expected, 3);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        cmp_array(v, expected, 3);
    }
}

TEST_CASE("Method at") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {0, -1, 1000};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE_THROWS(v.at(12));
        REQUIRE(v.at(0) == expected[0]);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE_THROWS(v.at(12));
        REQUIRE(v.at(0) == expected[0]);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE_THROWS(v.at(12));
        REQUIRE(v.at(0) == expected[0]);
    }
}

TEST_CASE("Method front") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0};
        for(std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(v.front() == v[0]);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(v.front() == v[0]);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(v.front() == v[0]);
    }
}

TEST_CASE("Method back") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0};
        for(std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(v.back() == v[2]);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(v.back() == v[2]);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(v.back() == v[2]);
    }
}

TEST_CASE("Method pointer") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0};
        for(std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(*v.data() == expected[0]);
        REQUIRE(v.data() != nullptr);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(v.data() != nullptr);
        REQUIRE(*v.data() == expected[0]);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+'};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        REQUIRE(v.data() != nullptr);
        REQUIRE(*v.data() == expected[0]);
    }
}

TEST_CASE("Method empty") {
    SECTION("int") {
        Vector<int> v{3};
        v.clear();
        REQUIRE(v.empty());
    }
    SECTION("double") {
        Vector<double> v{3};
        v.clear();
        REQUIRE(v.empty());
    }
    SECTION("char") {
        Vector<char> v{3};
        v.clear();
        REQUIRE(v.empty());
    }
}

TEST_CASE("Method size") {
    SECTION("int") {
        Vector<int> v{3};
        REQUIRE(v.size() == 3);
    }
    SECTION("double") {
        Vector<double> v{105};
        REQUIRE(v.size() == 105);
    }
    SECTION("char") {
        Vector<char> v{1000};
        REQUIRE(v.size() == 1000);
    }
}

TEST_CASE("Method capacity") {
    SECTION("int") {
        Vector<int> v{3};
        REQUIRE(v.size() <= v.capacity());
    }
    SECTION("double") {
        Vector<double> v{105};
        REQUIRE(v.size() <= v.capacity());
    }
    SECTION("char") {
        Vector<char> v{1000};
        REQUIRE(v.size() <= v.capacity());
    }
}


TEST_CASE("Method clear") {
    SECTION("int") {
        Vector<int> v{3};
        v.clear();
        REQUIRE(v.size() == 0);
    }
    SECTION("double") {
        Vector<double> v{3};
        v.clear();
        REQUIRE(v.size() == 0);
    }
    SECTION("char") {
        Vector<char> v{3};
        v.clear();
        REQUIRE(v.size() == 0);
    }
}

TEST_CASE("Method push_back") {
    SECTION("int") {
        Vector<int> v{3};
        int expected[] = {100, -1, 0, 4};
        for(std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        v.push_back(4);
        cmp_array(v, expected, 4);
    }
    SECTION("double") {
        Vector<double> v{3};
        double expected[] = {100.123, -1.01, 0.0, -10.088};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        v.push_back(-10.088);
        cmp_array(v, expected, 4);
    }
    SECTION("char") {
        Vector<char> v{3};
        char expected[] = {'h', '2', '+', 'n'};
        for (std::size_t i = 0; i < 3; ++i) {
            v[i] = expected[i];
        }
        v.push_back('n');
        cmp_array(v, expected, 4);
    }

}
