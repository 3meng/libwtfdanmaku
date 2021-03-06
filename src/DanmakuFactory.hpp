#ifndef _WTF_DANMAKU_FACTORY_HPP
#define _WTF_DANMAKU_FACTORY_HPP

#include <cstdint>
#include <string>
#include <memory>
#include "Noncopyable.hpp"
#include "BaseDanmaku.hpp"

using std::shared_ptr;

namespace WTFDanmaku {

    class DanmakuFactory : public Noncopyable {
    public:
        static DanmakuRef CreateDanmaku(DanmakuType type, time_t time, const std::wstring& comment, int fontSize, int fontColor, time_t timestamp = 0, uint64_t danmakuId = 0);
    };

}

#endif // _WTF_DANMAKU_FACTORY_HPP