#include "../../main.h"
#include "draw_sdcard.h"

my_sd_page_t sd_page;

static void create_btn(void);
static void create_size_label(void) ;
static void create_path_label(void);
static void update_path_label(char* path);
static void create_file_area(void);
static void update_file_list(char * path);

static void event_handler(lv_event_t* e) {

    lv_event_code_t code = lv_event_get_code(e); 

    if (code == LV_EVENT_RELEASED) {

        if(e->current_target == sd_page.btnReturn) {
            clear_sd_page();
        }
    }
}

void draw_sdcard(void) {
    // create_btn();
    create_path_label();
    create_file_area();
    update_file_list("/");
}

static void create_btn(void) {
    // sd_page.btnReturn = lv_btn_create(guider_ui.sculpture);
    // lv_obj_set_size(sd_page.btnReturn, 100, 50);
	// lv_obj_set_pos(sd_page.btnReturn, 1, 1);
	// lv_obj_add_event_cb(sd_page.btnReturn, event_handler, LV_EVENT_ALL, nullptr);

    sd_page.btnSDCard = lv_btn_create(guider_ui.sculpture);
    lv_obj_set_size(sd_page.btnSDCard, 100, 150);
	lv_obj_set_pos(sd_page.btnSDCard, 10, 100);
	lv_obj_add_event_cb(sd_page.btnSDCard, event_handler, LV_EVENT_ALL, nullptr);

}

static void create_size_label(void) {

    sd_page.labelSDcardSize = lv_label_create(guider_ui.sculpture);
    lv_obj_set_pos(sd_page.labelSDcardSize, 130, 30);
    lv_label_set_text_fmt(sd_page.labelSDcardSize, "Sdcard:%lluMB", mysdcard.get_sd_size());
}

static void create_path_label(void) {
    sd_page.labelSDcardPath = lv_label_create(guider_ui.sculpture);
    lv_obj_set_pos(sd_page.labelSDcardPath, 130, 30);
    lv_label_set_text_fmt(sd_page.labelSDcardPath, SD_ROOT_PATH);
}

static void update_path_label(char* path){
    // set text for lable
    lv_label_set_text_fmt(sd_page.labelSDcardPath, LV_SYMBOL_EYE_OPEN" %s", path);
}

static void brower_file_event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = (lv_obj_t *)lv_event_get_user_data(e);
    lv_obj_t * btn = lv_event_get_target(e);

    my_sd_page_t * explorer = (my_sd_page_t *)obj;
    std::string currentDir = mysdcard.getCurrentDir();

    if(code == LV_EVENT_VALUE_CHANGED) {
        //struct stat stat_buf;
        char * file_name[128];
        char * str_fn = NULL;
        uint16_t row;
        uint16_t col;

        memset(file_name, 0, sizeof(file_name));
        lv_table_get_selected_cell(explorer->file_list, &row, &col);
        str_fn = (char*)lv_table_get_cell_value(explorer->file_list, row, col);
        str_fn = str_fn+5;
        if((strcmp(str_fn, ".") == 0))  return;
        
        if((strcmp(str_fn, "..") == 0))
        {
            if(strcmp(currentDir.c_str(), "/") == 0){
                return ;
            }
            std::string upperDir = currentDir.substr(0, currentDir.rfind("/"));
            // myclient.client_write(CLIENT_SERIAL, (char*)upperDir.c_str());
            // myclient.client_write(CLIENT_SERIAL, "run here 2 \n");
            update_file_list((char*)upperDir.c_str());
            return ;        
        }

        std::string tmp(str_fn);
        std::string dir = currentDir+"/"+tmp;
        if( !mysdcard.isDirectory(SD, dir.c_str())){
            // 普通文件
            if(strcmp(str_fn, "..") != 0){
                // grbl_sendf 发送文件名到grbl
                // myclient.client_write(CLIENT_SERIAL, "run here 3 \n");
            }
        }
        else{
            update_file_list((char*)dir.c_str());  
            // myclient.client_write(CLIENT_SERIAL, "run here 4 \n");
        }

    }
    else if(code == LV_EVENT_SIZE_CHANGED) {
        lv_table_set_col_width(explorer->file_list, 0, lv_obj_get_width(explorer->file_list));
    }
}

static void create_file_area(void){
    sd_page.brower_area = lv_obj_create(guider_ui.sculpture);
    lv_obj_set_pos(sd_page.brower_area, 40, 70);
    lv_obj_set_size(sd_page.brower_area, 400, 210);
    lv_obj_set_flex_flow(sd_page.brower_area, LV_FLEX_FLOW_COLUMN);

    sd_page.file_list = lv_table_create(sd_page.brower_area);
    lv_obj_set_size(sd_page.file_list, LV_PCT(100), LV_PCT(100));
    lv_table_set_col_width(sd_page.file_list, 0, LV_PCT(100));
    lv_table_set_col_cnt(sd_page.file_list, 1);
    lv_obj_add_event_cb(sd_page.file_list, brower_file_event_handler, LV_EVENT_ALL, &sd_page);
    // only scroll up and down
    lv_obj_set_scroll_dir(sd_page.file_list, LV_DIR_TOP | LV_DIR_BOTTOM);
    
}

static void update_file_list(char * path){
    std::vector<std::string> fileList;
    std::vector<uint8_t>     fileType;
    uint16_t index = 0;

    update_path_label(path);

    // clean the file list object
    lv_table_set_cell_value_fmt(sd_page.file_list, index++, 0, LV_SYMBOL_DIRECTORY "  %s", ".");
    lv_table_set_cell_value_fmt(sd_page.file_list, index++, 0, LV_SYMBOL_DIRECTORY "  %s", "..");

    lv_table_set_cell_value(sd_page.file_list, 0, 1, "0");
    lv_table_set_cell_value(sd_page.file_list, 1, 1, "0");
   
    // get file list
    mysdcard.listDir(SD, path);
    fileList = mysdcard.getFileList();
    fileType = mysdcard.getFileType();

    for(int i = 0; i<fileList.size(); i++){
        std::string str = fileList[i];
        if(fileType[i] == 1){
            lv_table_set_cell_value_fmt(sd_page.file_list, index, 0, LV_SYMBOL_FILE "  %s", str.c_str());
        }
        else if(fileType[i] == 2){
            lv_table_set_cell_value_fmt(sd_page.file_list, index, 0, LV_SYMBOL_DIRECTORY "  %s", str.c_str());
        }
        lv_table_set_cell_value(sd_page.file_list, index, 1, "0");

        index++;
    }
    
    lv_table_set_row_cnt(sd_page.file_list, index);    // 刷新table cell长度的关键!
    // 让table移动到最顶部
    lv_obj_scroll_to_y(sd_page.file_list, 0, LV_ANIM_OFF);
}

void clear_sd_page(void) {
	lv_obj_clean(sd_page.brower_area);				
}