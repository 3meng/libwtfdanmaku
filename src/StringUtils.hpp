#ifndef _WTF_STRING_UTILS_HPP
#define _WTF_STRING_UTILS_HPP

#include <string>
#include <vector>

namespace WTFDanmaku {

    std::wstring UTF8ToWideString(const char* input);
    void SplitString(const char* input, char delimiter, std::vector<std::string>& output);
    void ReplaceStringInplace(std::wstring& str, const wchar_t* search, const wchar_t* replace);

    double StrTod(const std::string& str, double def = 0.0);
    float StrTof(const std::string& str, float def = 0.0f);
    int StrToi(const std::string& str, int def = 0, int base = 10);
    long long StrToll(const std::string& str, long long def = 0LL, int base = 10);
    unsigned long long StrToull(const std::string& str, unsigned long long def = 0ull, int base = 10);

}

#endif // _WTF_STRING_UTILS_HPP