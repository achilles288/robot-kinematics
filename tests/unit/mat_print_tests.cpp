#include <rk/matrix.h>
#include <gtest/gtest.h>

#include <codecvt>
#include <iostream>
#include <stdexcept>
#include <string>
#include <stdexcept>

using namespace std;


static void assert_wstring_eq(wstring expected, wstring actual) {
    if(actual != expected) {
        char *loc = setlocale(LC_ALL, 0);
        freopen(0, "a", stdout);
        setlocale(LC_ALL, "");
        
        wprintf(
          L"Expected print:\n%ls"
           "Actual print:\n%ls\n",
          expected.c_str(),
          actual.c_str()
        );
        
        freopen(0, "a", stdout);
        setlocale(LC_ALL, loc);
        
        FAIL();
    }
}


#define ASSERT_PRINT(X, FUNC) ({ \
    testing::internal::CaptureStdout(); \
    EXPECT_EXIT(((FUNC), exit(0)), \
                ::testing::ExitedWithCode(0),".*"); \
    string str = testing::internal::GetCapturedStdout(); \
    wstring out = wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(str); \
    if(::testing::Test::HasFailure()) \
        cout << str; \
    else \
        assert_wstring_eq((X), out); \
});


TEST(MatPrintTest, mat3) {
    rkMat3 M = (rkMat3) {{
      {0.9407f, -0.3391f, 23.005f},
      {0.3391f,  0.9407f, 17.340f}
    }};
    wstring expected = L"┌─                        ─┐\n"
                        "│ 0.9407, -0.3391, 23.0050 │\n"
                        "│ 0.3391,  0.9407, 17.3400 │\n"
                        "└─                        ─┘\n";
    ASSERT_PRINT(expected, rkMat3Print(M));
}

TEST(MatPrintTest, mat4) { 
    rkMat4 M = (rkMat4) {{
      {  0.1284f,  12.8835f, -0.4958f,  34.6600f},
      {-12.1800f, 138.8700f,  0.6441f, -54.3000f},
      { 14.0886f,   0.2193f, 34.9500f,   6.3450f}
    }};
    wstring expected = L"┌─                                     ─┐\n"
                        "│   0.1284,  12.8835, -0.4958,  34.6600 │\n"
                        "│ -12.1800, 138.8700,  0.6441, -54.3000 │\n"
                        "│  14.0886,   0.2193, 34.9500,   6.3450 │\n"
                        "└─                                     ─┘\n";
    ASSERT_PRINT(expected, rkMat4Print(M));
}

TEST(MatPrintTest, nanAndInf) { 
    rkMat3 M = (rkMat3) {{
      {11.0640f,       NAN,      NAN},
      {INFINITY, -INFINITY, 26.7421f}
    }};
    wstring expected = L"┌─                      ─┐\n"
                        "│ 11.0640,  nan,     nan │\n"
                        "│     inf, -inf, 26.7421 │\n"
                        "└─                      ─┘\n";
    ASSERT_PRINT(expected, rkMat3Print(M));
}

TEST(MatPrintTest, largeNumbers) { 
    rkMat3 M = (rkMat3) {{
      {255465394.5f , 3256539.06f,      76.53f},
      { -6554249.64f,   -5029.54f, 1345971.34f}
    }};
    wstring expected = L"┌─                                 ─┐\n"
                        "│  2.555e+08,  3.257e+06,   76.5300 │\n"
                        "│ -6.554e+06, -5029.5400, 1.346e+06 │\n"
                        "└─                                 ─┘\n";
    ASSERT_PRINT(expected, rkMat3Print(M));
}
