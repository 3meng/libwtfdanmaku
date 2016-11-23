#include "StringUtils.hpp"
#include <Windows.h>

namespace WTFDanmaku {

    std::wstring UTF8ToWideString(const char* input) {
        int length = MultiByteToWideChar(CP_UTF8, 0, input, -1, nullptr, 0);
        std::wstring result;
        if (length > 0) {
            result.resize(length);
            MultiByteToWideChar(CP_UTF8, 0, input, -1, const_cast<LPWSTR>(result.c_str()), length);
        }
        return result;
    }

    void SplitString(const char* input, char delimiter, std::vector<std::string>& output) {
        while (auto next = strchr(input, delimiter)) {
            output.push_back(std::string(input, next));
            input = next + 1;
        }
        output.push_back(std::string(input));
    }

    void ReplaceStringInplace(std::wstring& str, const wchar_t* search, const wchar_t* replace) {
        size_t search_length = wcslen(search);
        size_t replace_length = wcslen(replace);

        size_t pos = 0;
        while ((pos = str.find(search, pos)) != std::wstring::npos) {
            str.replace(pos, search_length, replace);
            pos += replace_length;
        }
    }

    inline double StrTod(const std::string& str, double def = 0.0)
    {
        const char *ptr = str.c_str();
        char *pend;

        errno = 0;
        double ret = ::strtod(ptr, &pend);
        if (ptr == pend || ERANGE == errno)
        {
            ret = def;
        }

        return ret;
    }

    inline float StrTof(const std::string& str, float def = 0.0f)
    {
        const char *ptr = str.c_str();
        char *pend;

        errno = 0;
        float ret = ::strtof(ptr, &pend);
        if (ptr == pend || ERANGE == errno)
        {
            ret = def;
        }

        return ret;
    }

    inline int StrToi(const std::string& str, int def = 0, int base = 10)
    {
        const char *ptr = str.c_str();
        char *pend;

        errno = 0;
        long ret = ::strtol(ptr, &pend, base);
        if (ptr == pend || ERANGE == errno || ret < INT_MIN || INT_MAX < ret)
        {
            ret = def;
        }

        return static_cast<int>(ret);
    }

    inline long long StrToll(const std::string& str, long long def = 0LL, int base = 10)
    {
        const char *ptr = str.c_str();
        char *pend;

        errno = 0;
        long long ret = ::strtoll(ptr, &pend, base);
        if (ptr == pend || ERANGE == errno)
        {
            ret = def;
        }

        return ret;
    }

    inline unsigned long long StrToull(const std::string& str, unsigned long long def = 0ull, int base = 10)
    {
        const char *ptr = str.c_str();
        char *pend;

        errno = 0;
        unsigned long long ret = ::strtoull(ptr, &pend, base);
        if (ptr == pend || ERANGE == errno)
        {
            ret = def;
        }

        return ret;
    }

}