#ifndef __fs_spi_h
#define __fs_spi_h

// #define USE_FS_SPIFFS
#define USE_FS_LITTLEFS

#ifdef USE_FS_SPIFFS
    #include <SPIFFS.h>
    #define COM_USE_FS      SPIFFS
#endif

#ifdef USE_FS_LITTLEFS
    #include <LittleFS.h>
    #define COM_USE_FS      LittleFS
#endif



class COM_FS {

private:

public:
    bool begin(void);
    void end(void);
    bool exists(const String& path);

    File open(const char* path, const char* mode = FILE_READ, const bool create = false);
    File open(const String& path, const char* mode = FILE_READ, const bool create = false);

    bool remove(const char* path);
    bool remove(const String& path);

    size_t totalBytes();
    size_t usedBytes();

    bool format();

};
extern COM_FS my_fs;

#endif
