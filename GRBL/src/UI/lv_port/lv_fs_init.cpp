#include "lv_fs.h"
#include "../../WebUI/fs_api.h"

File lv_file;

static void arduino_read_poix(void* buf, uint32_t btr, uint32_t* br) {
    uint32_t needToRead = btr;                                          /* 需要读出的数据长度 */ 
    uint32_t readNum = 0;                                               /* 实际读出的数据长度 */
    char *buff = (char *)buf;
    *br = lv_file.readBytes(buff, needToRead);                          /* 获取实际的数据长度 */
}

static bool my_fs_ready(lv_fs_drv_t* drv)
{
    return true;
}

static void * my_fs_open(struct _lv_fs_drv_t * drv, const char * path, lv_fs_mode_t mode) {

    File* tmp_file = &lv_file;
    if(mode == LV_FS_MODE_WR)           lv_file = my_fs.open(path, FILE_WRITE);
    else if(mode == LV_FS_MODE_RD)      lv_file = my_fs.open(path, FILE_READ);
    else if(mode == (LV_FS_MODE_WR|LV_FS_MODE_RD)) lv_file = my_fs.open(path, FILE_APPEND);

    if (!(*tmp_file)) {
        return nullptr;
    }else {
        return tmp_file;
    }
}

static lv_fs_res_t my_fs_close(lv_fs_drv_t* drv, void* file_p)
{   
    lv_file.close();
    return LV_FS_RES_OK;
}

static lv_fs_res_t my_fs_write(lv_fs_drv_t* drv, void* file_p, const void* buf, uint32_t btw, uint32_t* bw)
{
    return LV_FS_RES_OK;
}


static lv_fs_res_t fs_read(lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br)
{   
    grbl_send(CLIENT_SERIAL, "enter read\n");
    arduino_read_poix(buf, btr, br);
    return LV_FS_RES_OK;
}

static lv_fs_res_t my_fs_seek(lv_fs_drv_t* drv, void* file_p, uint32_t pos, lv_fs_whence_t whence)
{   
    grbl_send(CLIENT_SERIAL, "enter seek\n");
    lv_file.seek(pos);
    return LV_FS_RES_OK;
}

static lv_fs_res_t my_fs_tell(lv_fs_drv_t* drv, void* file_p, uint32_t* pos_p)
{   
    grbl_send(CLIENT_SERIAL, "enter tell\n");
    *pos_p = lv_file.position();
    return LV_FS_RES_OK;
}

void LVGL_UI::lvPortFsInit(void) {

    static lv_fs_drv_t drv;       
       
    lv_fs_drv_init(&drv);

    drv.letter = 'M';                                       /* 意味着是my_fs */       
    drv.ready_cb = my_fs_ready; 
    drv.open_cb = my_fs_open;
    drv.close_cb = my_fs_close;
    drv.read_cb = fs_read;
    drv.write_cb = my_fs_write;
    drv.seek_cb = my_fs_seek;
    drv.tell_cb = my_fs_tell;
    lv_fs_drv_register(&drv);
}