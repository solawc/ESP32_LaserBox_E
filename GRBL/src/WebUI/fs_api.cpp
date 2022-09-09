#include "fs_api.h"

COM_FS my_fs;

bool COM_FS::begin(void) {
#ifdef USE_FS_SPIFFS
    return SPIFFS.begin(true);
#endif

#ifdef USE_FS_LITTLEFS
    return LittleFS.begin(true);
#endif
}

void COM_FS::end(void) {

#ifdef USE_FS_SPIFFS
    return SPIFFS.end();
#endif

#ifdef USE_FS_LITTLEFS
    return LittleFS.end();
#endif
}

bool COM_FS::exists(const String& path) {

#ifdef USE_FS_SPIFFS
    return SPIFFS.exists(path);
#endif

#ifdef USE_FS_LITTLEFS
    return LittleFS.exists(path);
#endif
    
}

File COM_FS::open(const char* path, const char* mode, const bool create) {

#ifdef USE_FS_SPIFFS
    return SPIFFS.open(path, mode, create);
#endif

#ifdef USE_FS_LITTLEFS
    return LittleFS.open(path, mode, create);
#endif
}

File COM_FS::open(const String& path, const char* mode, const bool create)
{
    return open(path.c_str(), mode, create);
}

bool COM_FS::remove(const char* path) {


#ifdef USE_FS_SPIFFS
    return SPIFFS.remove(path);
#endif

#ifdef USE_FS_LITTLEFS
    return LittleFS.remove(path);
#endif
}

bool COM_FS::remove(const String& path)
{
    return remove(path.c_str());
}

size_t COM_FS::totalBytes() {

#ifdef USE_FS_SPIFFS
    return SPIFFS.totalBytes();
#endif

#ifdef USE_FS_LITTLEFS
    return LittleFS.totalBytes();
#endif
}

size_t COM_FS::usedBytes() {

#ifdef USE_FS_SPIFFS
    return SPIFFS.usedBytes();
#endif

#ifdef USE_FS_LITTLEFS
    return LittleFS.usedBytes();
#endif
}

bool COM_FS::format() {
#ifdef USE_FS_SPIFFS
    return SPIFFS.usedBytes();
#endif

#ifdef USE_FS_LITTLEFS
    return LittleFS.format();
#endif
}


