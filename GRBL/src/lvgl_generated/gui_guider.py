# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=480,h=320)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(480*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 480
disp_drv.ver_res = 320
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)


home = lv.obj()
home.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_main_main_default
style_home_main_main_default = lv.style_t()
style_home_main_main_default.init()
style_home_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_home_main_main_default.set_bg_opa(255)

# add style for home
home.add_style(style_home_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_btn_tool = lv.btn(home)
home_btn_tool.set_pos(int(18),int(44))
home_btn_tool.set_size(110,32)
home_btn_tool.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_btn_tool_label = lv.label(home_btn_tool)
home_btn_tool_label.set_text("Tool")
home_btn_tool.set_style_pad_all(0, lv.STATE.DEFAULT)
home_btn_tool_label.align(lv.ALIGN.CENTER,0,0)
# create style style_home_btn_tool_main_main_default
style_home_btn_tool_main_main_default = lv.style_t()
style_home_btn_tool_main_main_default.init()
style_home_btn_tool_main_main_default.set_radius(5)
style_home_btn_tool_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_home_btn_tool_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_tool_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_btn_tool_main_main_default.set_bg_opa(255)
style_home_btn_tool_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_tool_main_main_default.set_border_width(0)
style_home_btn_tool_main_main_default.set_border_opa(255)
style_home_btn_tool_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_btn_tool_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_btn_tool_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_btn_tool_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_btn_tool_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for home_btn_tool
home_btn_tool.add_style(style_home_btn_tool_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_btn_larsepower = lv.btn(home)
home_btn_larsepower.set_pos(int(18),int(94))
home_btn_larsepower.set_size(110,32)
home_btn_larsepower.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_btn_larsepower_label = lv.label(home_btn_larsepower)
home_btn_larsepower_label.set_text("Larse Power")
home_btn_larsepower.set_style_pad_all(0, lv.STATE.DEFAULT)
home_btn_larsepower_label.align(lv.ALIGN.CENTER,0,0)
# create style style_home_btn_larsepower_main_main_default
style_home_btn_larsepower_main_main_default = lv.style_t()
style_home_btn_larsepower_main_main_default.init()
style_home_btn_larsepower_main_main_default.set_radius(5)
style_home_btn_larsepower_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_home_btn_larsepower_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_larsepower_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_btn_larsepower_main_main_default.set_bg_opa(255)
style_home_btn_larsepower_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_larsepower_main_main_default.set_border_width(0)
style_home_btn_larsepower_main_main_default.set_border_opa(255)
style_home_btn_larsepower_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_btn_larsepower_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_btn_larsepower_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_btn_larsepower_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_btn_larsepower_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for home_btn_larsepower
home_btn_larsepower.add_style(style_home_btn_larsepower_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_btn_about = lv.btn(home)
home_btn_about.set_pos(int(18),int(244))
home_btn_about.set_size(110,32)
home_btn_about.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_btn_about_label = lv.label(home_btn_about)
home_btn_about_label.set_text("About")
home_btn_about.set_style_pad_all(0, lv.STATE.DEFAULT)
home_btn_about_label.align(lv.ALIGN.CENTER,0,0)
# create style style_home_btn_about_main_main_default
style_home_btn_about_main_main_default = lv.style_t()
style_home_btn_about_main_main_default.init()
style_home_btn_about_main_main_default.set_radius(5)
style_home_btn_about_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_home_btn_about_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_about_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_btn_about_main_main_default.set_bg_opa(255)
style_home_btn_about_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_about_main_main_default.set_border_width(0)
style_home_btn_about_main_main_default.set_border_opa(255)
style_home_btn_about_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_btn_about_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_btn_about_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_btn_about_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_btn_about_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for home_btn_about
home_btn_about.add_style(style_home_btn_about_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_btn_setting = lv.btn(home)
home_btn_setting.set_pos(int(18),int(194))
home_btn_setting.set_size(110,32)
home_btn_setting.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_btn_setting_label = lv.label(home_btn_setting)
home_btn_setting_label.set_text("Setting")
home_btn_setting.set_style_pad_all(0, lv.STATE.DEFAULT)
home_btn_setting_label.align(lv.ALIGN.CENTER,0,0)
# create style style_home_btn_setting_main_main_default
style_home_btn_setting_main_main_default = lv.style_t()
style_home_btn_setting_main_main_default.init()
style_home_btn_setting_main_main_default.set_radius(5)
style_home_btn_setting_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_home_btn_setting_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_setting_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_btn_setting_main_main_default.set_bg_opa(255)
style_home_btn_setting_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_setting_main_main_default.set_border_width(0)
style_home_btn_setting_main_main_default.set_border_opa(255)
style_home_btn_setting_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_btn_setting_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_btn_setting_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_btn_setting_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_btn_setting_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for home_btn_setting
home_btn_setting.add_style(style_home_btn_setting_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_btn_sculpture = lv.btn(home)
home_btn_sculpture.set_pos(int(18),int(144))
home_btn_sculpture.set_size(110,32)
home_btn_sculpture.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_btn_sculpture_label = lv.label(home_btn_sculpture)
home_btn_sculpture_label.set_text("Sculpture")
home_btn_sculpture.set_style_pad_all(0, lv.STATE.DEFAULT)
home_btn_sculpture_label.align(lv.ALIGN.CENTER,0,0)
# create style style_home_btn_sculpture_main_main_default
style_home_btn_sculpture_main_main_default = lv.style_t()
style_home_btn_sculpture_main_main_default.init()
style_home_btn_sculpture_main_main_default.set_radius(5)
style_home_btn_sculpture_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_home_btn_sculpture_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_sculpture_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_btn_sculpture_main_main_default.set_bg_opa(255)
style_home_btn_sculpture_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_home_btn_sculpture_main_main_default.set_border_width(0)
style_home_btn_sculpture_main_main_default.set_border_opa(255)
style_home_btn_sculpture_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_btn_sculpture_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_btn_sculpture_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_btn_sculpture_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_btn_sculpture_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)

# add style for home_btn_sculpture
home_btn_sculpture.add_style(style_home_btn_sculpture_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_cont_1 = lv.obj(home)
home_cont_1.set_pos(int(152),int(50))
home_cont_1.set_size(300,171)
home_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_cont_1_main_main_default
style_home_cont_1_main_main_default = lv.style_t()
style_home_cont_1_main_main_default.init()
style_home_cont_1_main_main_default.set_radius(0)
style_home_cont_1_main_main_default.set_bg_color(lv.color_make(0xff,0xb8,0xc1))
style_home_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_cont_1_main_main_default.set_bg_opa(255)
style_home_cont_1_main_main_default.set_shadow_width(15)
style_home_cont_1_main_main_default.set_shadow_color(lv.color_make(0xbe,0xb7,0xb7))
style_home_cont_1_main_main_default.set_shadow_opa(255)
style_home_cont_1_main_main_default.set_shadow_spread(15)
style_home_cont_1_main_main_default.set_shadow_ofs_x(2)
style_home_cont_1_main_main_default.set_shadow_ofs_y(2)
style_home_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_home_cont_1_main_main_default.set_border_width(0)
style_home_cont_1_main_main_default.set_border_opa(255)
style_home_cont_1_main_main_default.set_pad_left(0)
style_home_cont_1_main_main_default.set_pad_right(0)
style_home_cont_1_main_main_default.set_pad_top(0)
style_home_cont_1_main_main_default.set_pad_bottom(0)

# add style for home_cont_1
home_cont_1.add_style(style_home_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_m_z = lv.label(home)
home_label_m_z.set_pos(int(339),int(168))
home_label_m_z.set_size(25,19)
home_label_m_z.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_m_z.set_text("z:")
home_label_m_z.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_m_z_main_main_default
style_home_label_m_z_main_main_default = lv.style_t()
style_home_label_m_z_main_main_default.init()
style_home_label_m_z_main_main_default.set_radius(0)
style_home_label_m_z_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_m_z_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_m_z_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_m_z_main_main_default.set_bg_opa(0)
style_home_label_m_z_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_m_z_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_m_z_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_m_z_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_m_z_main_main_default.set_text_letter_space(2)
style_home_label_m_z_main_main_default.set_text_line_space(0)
style_home_label_m_z_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_m_z_main_main_default.set_pad_left(0)
style_home_label_m_z_main_main_default.set_pad_right(0)
style_home_label_m_z_main_main_default.set_pad_top(0)
style_home_label_m_z_main_main_default.set_pad_bottom(0)

# add style for home_label_m_z
home_label_m_z.add_style(style_home_label_m_z_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_cont_2 = lv.obj(home)
home_cont_2.set_pos(int(178),int(69))
home_cont_2.set_size(250,133)
home_cont_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_w_z = lv.label(home_cont_2)
home_label_w_z.set_pos(int(162),int(34))
home_label_w_z.set_size(25,19)
home_label_w_z.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_w_z.set_text("z:")
home_label_w_z.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_w_z_main_main_default
style_home_label_w_z_main_main_default = lv.style_t()
style_home_label_w_z_main_main_default.init()
style_home_label_w_z_main_main_default.set_radius(0)
style_home_label_w_z_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_w_z_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_w_z_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_w_z_main_main_default.set_bg_opa(0)
style_home_label_w_z_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_w_z_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_w_z_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_w_z_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_w_z_main_main_default.set_text_letter_space(2)
style_home_label_w_z_main_main_default.set_text_line_space(0)
style_home_label_w_z_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_w_z_main_main_default.set_pad_left(0)
style_home_label_w_z_main_main_default.set_pad_right(0)
style_home_label_w_z_main_main_default.set_pad_top(0)
style_home_label_w_z_main_main_default.set_pad_bottom(0)

# add style for home_label_w_z
home_label_w_z.add_style(style_home_label_w_z_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_4 = lv.label(home_cont_2)
home_label_4.set_pos(int(-3),int(72))
home_label_4.set_size(174,13)
home_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_4.set_text("Machine coordinates")
home_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_4_main_main_default
style_home_label_4_main_main_default = lv.style_t()
style_home_label_4_main_main_default.init()
style_home_label_4_main_main_default.set_radius(0)
style_home_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_4_main_main_default.set_bg_opa(0)
style_home_label_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_4_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_4_main_main_default.set_text_letter_space(2)
style_home_label_4_main_main_default.set_text_line_space(0)
style_home_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_4_main_main_default.set_pad_left(0)
style_home_label_4_main_main_default.set_pad_right(0)
style_home_label_4_main_main_default.set_pad_top(0)
style_home_label_4_main_main_default.set_pad_bottom(0)

# add style for home_label_4
home_label_4.add_style(style_home_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_cont_2_main_main_default
style_home_cont_2_main_main_default = lv.style_t()
style_home_cont_2_main_main_default.init()
style_home_cont_2_main_main_default.set_radius(0)
style_home_cont_2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_home_cont_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_cont_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_cont_2_main_main_default.set_bg_opa(255)
style_home_cont_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_home_cont_2_main_main_default.set_border_width(0)
style_home_cont_2_main_main_default.set_border_opa(255)
style_home_cont_2_main_main_default.set_pad_left(0)
style_home_cont_2_main_main_default.set_pad_right(0)
style_home_cont_2_main_main_default.set_pad_top(0)
style_home_cont_2_main_main_default.set_pad_bottom(0)

# add style for home_cont_2
home_cont_2.add_style(style_home_cont_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_m_y = lv.label(home)
home_label_m_y.set_pos(int(264),int(168))
home_label_m_y.set_size(28,19)
home_label_m_y.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_m_y.set_text("y:")
home_label_m_y.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_m_y_main_main_default
style_home_label_m_y_main_main_default = lv.style_t()
style_home_label_m_y_main_main_default.init()
style_home_label_m_y_main_main_default.set_radius(0)
style_home_label_m_y_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_m_y_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_m_y_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_m_y_main_main_default.set_bg_opa(0)
style_home_label_m_y_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_m_y_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_m_y_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_m_y_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_m_y_main_main_default.set_text_letter_space(2)
style_home_label_m_y_main_main_default.set_text_line_space(0)
style_home_label_m_y_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_m_y_main_main_default.set_pad_left(0)
style_home_label_m_y_main_main_default.set_pad_right(0)
style_home_label_m_y_main_main_default.set_pad_top(0)
style_home_label_m_y_main_main_default.set_pad_bottom(0)

# add style for home_label_m_y
home_label_m_y.add_style(style_home_label_m_y_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_m_x = lv.label(home)
home_label_m_x.set_pos(int(188),int(168))
home_label_m_x.set_size(29,13)
home_label_m_x.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_m_x.set_text("x:")
home_label_m_x.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_m_x_main_main_default
style_home_label_m_x_main_main_default = lv.style_t()
style_home_label_m_x_main_main_default.init()
style_home_label_m_x_main_main_default.set_radius(0)
style_home_label_m_x_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_m_x_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_m_x_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_m_x_main_main_default.set_bg_opa(0)
style_home_label_m_x_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_m_x_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_m_x_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_m_x_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_m_x_main_main_default.set_text_letter_space(2)
style_home_label_m_x_main_main_default.set_text_line_space(0)
style_home_label_m_x_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_m_x_main_main_default.set_pad_left(0)
style_home_label_m_x_main_main_default.set_pad_right(0)
style_home_label_m_x_main_main_default.set_pad_top(0)
style_home_label_m_x_main_main_default.set_pad_bottom(0)

# add style for home_label_m_x
home_label_m_x.add_style(style_home_label_m_x_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_machine_coordinates_y = lv.label(home)
home_label_machine_coordinates_y.set_pos(int(281),int(168))
home_label_machine_coordinates_y.set_size(56,24)
home_label_machine_coordinates_y.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_machine_coordinates_y.set_text("0.00")
home_label_machine_coordinates_y.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_machine_coordinates_y_main_main_default
style_home_label_machine_coordinates_y_main_main_default = lv.style_t()
style_home_label_machine_coordinates_y_main_main_default.init()
style_home_label_machine_coordinates_y_main_main_default.set_radius(0)
style_home_label_machine_coordinates_y_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_machine_coordinates_y_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_machine_coordinates_y_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_machine_coordinates_y_main_main_default.set_bg_opa(0)
style_home_label_machine_coordinates_y_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_machine_coordinates_y_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_machine_coordinates_y_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_machine_coordinates_y_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_machine_coordinates_y_main_main_default.set_text_letter_space(2)
style_home_label_machine_coordinates_y_main_main_default.set_text_line_space(0)
style_home_label_machine_coordinates_y_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_machine_coordinates_y_main_main_default.set_pad_left(0)
style_home_label_machine_coordinates_y_main_main_default.set_pad_right(0)
style_home_label_machine_coordinates_y_main_main_default.set_pad_top(0)
style_home_label_machine_coordinates_y_main_main_default.set_pad_bottom(0)

# add style for home_label_machine_coordinates_y
home_label_machine_coordinates_y.add_style(style_home_label_machine_coordinates_y_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_machine_coordinates_z = lv.label(home)
home_label_machine_coordinates_z.set_pos(int(360),int(168))
home_label_machine_coordinates_z.set_size(53,22)
home_label_machine_coordinates_z.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_machine_coordinates_z.set_text("0.00")
home_label_machine_coordinates_z.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_machine_coordinates_z_main_main_default
style_home_label_machine_coordinates_z_main_main_default = lv.style_t()
style_home_label_machine_coordinates_z_main_main_default.init()
style_home_label_machine_coordinates_z_main_main_default.set_radius(0)
style_home_label_machine_coordinates_z_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_machine_coordinates_z_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_machine_coordinates_z_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_machine_coordinates_z_main_main_default.set_bg_opa(0)
style_home_label_machine_coordinates_z_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_machine_coordinates_z_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_machine_coordinates_z_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_machine_coordinates_z_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_machine_coordinates_z_main_main_default.set_text_letter_space(2)
style_home_label_machine_coordinates_z_main_main_default.set_text_line_space(0)
style_home_label_machine_coordinates_z_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_machine_coordinates_z_main_main_default.set_pad_left(0)
style_home_label_machine_coordinates_z_main_main_default.set_pad_right(0)
style_home_label_machine_coordinates_z_main_main_default.set_pad_top(0)
style_home_label_machine_coordinates_z_main_main_default.set_pad_bottom(0)

# add style for home_label_machine_coordinates_z
home_label_machine_coordinates_z.add_style(style_home_label_machine_coordinates_z_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_work_coordinates_z = lv.label(home)
home_label_work_coordinates_z.set_pos(int(354),int(104))
home_label_work_coordinates_z.set_size(64,25)
home_label_work_coordinates_z.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_work_coordinates_z.set_text("0.00")
home_label_work_coordinates_z.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_work_coordinates_z_main_main_default
style_home_label_work_coordinates_z_main_main_default = lv.style_t()
style_home_label_work_coordinates_z_main_main_default.init()
style_home_label_work_coordinates_z_main_main_default.set_radius(0)
style_home_label_work_coordinates_z_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_work_coordinates_z_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_work_coordinates_z_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_work_coordinates_z_main_main_default.set_bg_opa(0)
style_home_label_work_coordinates_z_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_work_coordinates_z_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_work_coordinates_z_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_work_coordinates_z_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_work_coordinates_z_main_main_default.set_text_letter_space(2)
style_home_label_work_coordinates_z_main_main_default.set_text_line_space(0)
style_home_label_work_coordinates_z_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_work_coordinates_z_main_main_default.set_pad_left(0)
style_home_label_work_coordinates_z_main_main_default.set_pad_right(0)
style_home_label_work_coordinates_z_main_main_default.set_pad_top(0)
style_home_label_work_coordinates_z_main_main_default.set_pad_bottom(0)

# add style for home_label_work_coordinates_z
home_label_work_coordinates_z.add_style(style_home_label_work_coordinates_z_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_work_coordinates_y = lv.label(home)
home_label_work_coordinates_y.set_pos(int(281),int(104))
home_label_work_coordinates_y.set_size(58,17)
home_label_work_coordinates_y.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_work_coordinates_y.set_text("0.00")
home_label_work_coordinates_y.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_work_coordinates_y_main_main_default
style_home_label_work_coordinates_y_main_main_default = lv.style_t()
style_home_label_work_coordinates_y_main_main_default.init()
style_home_label_work_coordinates_y_main_main_default.set_radius(0)
style_home_label_work_coordinates_y_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_work_coordinates_y_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_work_coordinates_y_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_work_coordinates_y_main_main_default.set_bg_opa(0)
style_home_label_work_coordinates_y_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_work_coordinates_y_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_work_coordinates_y_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_work_coordinates_y_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_work_coordinates_y_main_main_default.set_text_letter_space(2)
style_home_label_work_coordinates_y_main_main_default.set_text_line_space(0)
style_home_label_work_coordinates_y_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_work_coordinates_y_main_main_default.set_pad_left(0)
style_home_label_work_coordinates_y_main_main_default.set_pad_right(0)
style_home_label_work_coordinates_y_main_main_default.set_pad_top(0)
style_home_label_work_coordinates_y_main_main_default.set_pad_bottom(0)

# add style for home_label_work_coordinates_y
home_label_work_coordinates_y.add_style(style_home_label_work_coordinates_y_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_3 = lv.label(home)
home_label_3.set_pos(int(174),int(74))
home_label_3.set_size(151,11)
home_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_3.set_text("Work coordinates")
home_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_3_main_main_default
style_home_label_3_main_main_default = lv.style_t()
style_home_label_3_main_main_default.init()
style_home_label_3_main_main_default.set_radius(0)
style_home_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_3_main_main_default.set_bg_opa(0)
style_home_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_3_main_main_default.set_text_letter_space(2)
style_home_label_3_main_main_default.set_text_line_space(0)
style_home_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_3_main_main_default.set_pad_left(0)
style_home_label_3_main_main_default.set_pad_right(0)
style_home_label_3_main_main_default.set_pad_top(0)
style_home_label_3_main_main_default.set_pad_bottom(0)

# add style for home_label_3
home_label_3.add_style(style_home_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_status = lv.label(home)
home_label_status.set_pos(int(152),int(250))
home_label_status.set_size(105,24)
home_label_status.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_status.set_text("Status")
home_label_status.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_status_main_main_default
style_home_label_status_main_main_default = lv.style_t()
style_home_label_status_main_main_default.init()
style_home_label_status_main_main_default.set_radius(0)
style_home_label_status_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_home_label_status_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_status_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_status_main_main_default.set_bg_opa(255)
style_home_label_status_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_status_main_main_default.set_text_font(lv.font_Amiko_Regular_16)
except AttributeError:
    try:
        style_home_label_status_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_label_status_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_status_main_main_default.set_text_letter_space(2)
style_home_label_status_main_main_default.set_text_line_space(0)
style_home_label_status_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_status_main_main_default.set_pad_left(0)
style_home_label_status_main_main_default.set_pad_right(0)
style_home_label_status_main_main_default.set_pad_top(0)
style_home_label_status_main_main_default.set_pad_bottom(0)

# add style for home_label_status
home_label_status.add_style(style_home_label_status_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_machine_status = lv.label(home)
home_label_machine_status.set_pos(int(264),int(252))
home_label_machine_status.set_size(175,22)
home_label_machine_status.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_machine_status.set_text("Not connected")
home_label_machine_status.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_machine_status_main_main_default
style_home_label_machine_status_main_main_default = lv.style_t()
style_home_label_machine_status_main_main_default.init()
style_home_label_machine_status_main_main_default.set_radius(0)
style_home_label_machine_status_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_machine_status_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_machine_status_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_machine_status_main_main_default.set_bg_opa(0)
style_home_label_machine_status_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_machine_status_main_main_default.set_text_font(lv.font_simsun_16)
except AttributeError:
    try:
        style_home_label_machine_status_main_main_default.set_text_font(lv.font_montserrat_16)
    except AttributeError:
        style_home_label_machine_status_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_machine_status_main_main_default.set_text_letter_space(2)
style_home_label_machine_status_main_main_default.set_text_line_space(0)
style_home_label_machine_status_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_machine_status_main_main_default.set_pad_left(0)
style_home_label_machine_status_main_main_default.set_pad_right(0)
style_home_label_machine_status_main_main_default.set_pad_top(0)
style_home_label_machine_status_main_main_default.set_pad_bottom(0)

# add style for home_label_machine_status
home_label_machine_status.add_style(style_home_label_machine_status_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_w_x = lv.label(home)
home_label_w_x.set_pos(int(188),int(104))
home_label_w_x.set_size(29,13)
home_label_w_x.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_w_x.set_text("x:")
home_label_w_x.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_w_x_main_main_default
style_home_label_w_x_main_main_default = lv.style_t()
style_home_label_w_x_main_main_default.init()
style_home_label_w_x_main_main_default.set_radius(0)
style_home_label_w_x_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_w_x_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_w_x_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_w_x_main_main_default.set_bg_opa(0)
style_home_label_w_x_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_w_x_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_w_x_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_w_x_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_w_x_main_main_default.set_text_letter_space(2)
style_home_label_w_x_main_main_default.set_text_line_space(0)
style_home_label_w_x_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_w_x_main_main_default.set_pad_left(0)
style_home_label_w_x_main_main_default.set_pad_right(0)
style_home_label_w_x_main_main_default.set_pad_top(0)
style_home_label_w_x_main_main_default.set_pad_bottom(0)

# add style for home_label_w_x
home_label_w_x.add_style(style_home_label_w_x_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_w_y = lv.label(home)
home_label_w_y.set_pos(int(269),int(104))
home_label_w_y.set_size(28,19)
home_label_w_y.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_w_y.set_text("y:")
home_label_w_y.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_w_y_main_main_default
style_home_label_w_y_main_main_default = lv.style_t()
style_home_label_w_y_main_main_default.init()
style_home_label_w_y_main_main_default.set_radius(0)
style_home_label_w_y_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_w_y_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_w_y_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_w_y_main_main_default.set_bg_opa(0)
style_home_label_w_y_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_w_y_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_w_y_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_w_y_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_w_y_main_main_default.set_text_letter_space(2)
style_home_label_w_y_main_main_default.set_text_line_space(0)
style_home_label_w_y_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_w_y_main_main_default.set_pad_left(0)
style_home_label_w_y_main_main_default.set_pad_right(0)
style_home_label_w_y_main_main_default.set_pad_top(0)
style_home_label_w_y_main_main_default.set_pad_bottom(0)

# add style for home_label_w_y
home_label_w_y.add_style(style_home_label_w_y_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_work_coordinates_x = lv.label(home)
home_label_work_coordinates_x.set_pos(int(207),int(104))
home_label_work_coordinates_x.set_size(57,14)
home_label_work_coordinates_x.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_work_coordinates_x.set_text("0.00")
home_label_work_coordinates_x.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_work_coordinates_x_main_main_default
style_home_label_work_coordinates_x_main_main_default = lv.style_t()
style_home_label_work_coordinates_x_main_main_default.init()
style_home_label_work_coordinates_x_main_main_default.set_radius(0)
style_home_label_work_coordinates_x_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_work_coordinates_x_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_work_coordinates_x_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_work_coordinates_x_main_main_default.set_bg_opa(0)
style_home_label_work_coordinates_x_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_work_coordinates_x_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_work_coordinates_x_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_work_coordinates_x_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_work_coordinates_x_main_main_default.set_text_letter_space(2)
style_home_label_work_coordinates_x_main_main_default.set_text_line_space(0)
style_home_label_work_coordinates_x_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_work_coordinates_x_main_main_default.set_pad_left(0)
style_home_label_work_coordinates_x_main_main_default.set_pad_right(0)
style_home_label_work_coordinates_x_main_main_default.set_pad_top(0)
style_home_label_work_coordinates_x_main_main_default.set_pad_bottom(0)

# add style for home_label_work_coordinates_x
home_label_work_coordinates_x.add_style(style_home_label_work_coordinates_x_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_label_machine_coordinates_x = lv.label(home)
home_label_machine_coordinates_x.set_pos(int(207),int(168))
home_label_machine_coordinates_x.set_size(55,19)
home_label_machine_coordinates_x.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_label_machine_coordinates_x.set_text("0.00")
home_label_machine_coordinates_x.set_long_mode(lv.label.LONG.WRAP)
# create style style_home_label_machine_coordinates_x_main_main_default
style_home_label_machine_coordinates_x_main_main_default = lv.style_t()
style_home_label_machine_coordinates_x_main_main_default.init()
style_home_label_machine_coordinates_x_main_main_default.set_radius(0)
style_home_label_machine_coordinates_x_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_machine_coordinates_x_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_label_machine_coordinates_x_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_label_machine_coordinates_x_main_main_default.set_bg_opa(0)
style_home_label_machine_coordinates_x_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_home_label_machine_coordinates_x_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_label_machine_coordinates_x_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_label_machine_coordinates_x_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_label_machine_coordinates_x_main_main_default.set_text_letter_space(2)
style_home_label_machine_coordinates_x_main_main_default.set_text_line_space(0)
style_home_label_machine_coordinates_x_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_label_machine_coordinates_x_main_main_default.set_pad_left(0)
style_home_label_machine_coordinates_x_main_main_default.set_pad_right(0)
style_home_label_machine_coordinates_x_main_main_default.set_pad_top(0)
style_home_label_machine_coordinates_x_main_main_default.set_pad_bottom(0)

# add style for home_label_machine_coordinates_x
home_label_machine_coordinates_x.add_style(style_home_label_machine_coordinates_x_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool = lv.obj()
tool.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_tool_main_main_default
style_tool_main_main_default = lv.style_t()
style_tool_main_main_default.init()
style_tool_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_tool_main_main_default.set_bg_opa(255)

# add style for tool
tool.add_style(style_tool_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_cont_1 = lv.obj(tool)
tool_cont_1.set_pos(int(292),int(117))
tool_cont_1.set_size(171,111)
tool_cont_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_ddlist_2 = lv.dropdown(tool_cont_1)
tool_ddlist_2.set_pos(int(73),int(69))
tool_ddlist_2.set_size(72,28)
tool_ddlist_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_ddlist_2.set_options("list1\nlist2\nlist3")

tool_ddlist_2_list = tool_ddlist_2.get_list()
# create style style_tool_ddlist_2_extra_list_selected_checked
style_tool_ddlist_2_extra_list_selected_checked = lv.style_t()
style_tool_ddlist_2_extra_list_selected_checked.init()
style_tool_ddlist_2_extra_list_selected_checked.set_radius(3)
style_tool_ddlist_2_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_tool_ddlist_2_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_tool_ddlist_2_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_ddlist_2_extra_list_selected_checked.set_bg_opa(255)
style_tool_ddlist_2_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_tool_ddlist_2_extra_list_selected_checked.set_border_width(1)
style_tool_ddlist_2_extra_list_selected_checked.set_border_opa(255)
style_tool_ddlist_2_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_ddlist_2_extra_list_selected_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_ddlist_2_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_ddlist_2_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)
style_tool_ddlist_2_extra_list_selected_checked.set_pad_left(6)
style_tool_ddlist_2_extra_list_selected_checked.set_pad_right(6)
style_tool_ddlist_2_extra_list_selected_checked.set_pad_top(6)
style_tool_ddlist_2_extra_list_selected_checked.set_pad_bottom(6)

# add style for tool_ddlist_2_list
tool_ddlist_2_list.add_style(style_tool_ddlist_2_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_tool_ddlist_2_extra_list_main_default
style_tool_ddlist_2_extra_list_main_default = lv.style_t()
style_tool_ddlist_2_extra_list_main_default.init()
style_tool_ddlist_2_extra_list_main_default.set_radius(3)
style_tool_ddlist_2_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_tool_ddlist_2_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_tool_ddlist_2_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_ddlist_2_extra_list_main_default.set_bg_opa(255)
style_tool_ddlist_2_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_tool_ddlist_2_extra_list_main_default.set_border_width(1)
style_tool_ddlist_2_extra_list_main_default.set_border_opa(255)
style_tool_ddlist_2_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_tool_ddlist_2_extra_list_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_ddlist_2_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_ddlist_2_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_tool_ddlist_2_extra_list_main_default.set_pad_left(6)
style_tool_ddlist_2_extra_list_main_default.set_pad_right(6)
style_tool_ddlist_2_extra_list_main_default.set_pad_top(6)
style_tool_ddlist_2_extra_list_main_default.set_pad_bottom(6)
style_tool_ddlist_2_extra_list_main_default.set_max_height(90)

# add style for tool_ddlist_2_list
tool_ddlist_2_list.add_style(style_tool_ddlist_2_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_ddlist_2_extra_list_scrollbar_default
style_tool_ddlist_2_extra_list_scrollbar_default = lv.style_t()
style_tool_ddlist_2_extra_list_scrollbar_default.init()
style_tool_ddlist_2_extra_list_scrollbar_default.set_radius(3)
style_tool_ddlist_2_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_tool_ddlist_2_extra_list_scrollbar_default.set_bg_opa(255)
style_tool_ddlist_2_extra_list_scrollbar_default.set_pad_left(6)
style_tool_ddlist_2_extra_list_scrollbar_default.set_pad_right(6)
style_tool_ddlist_2_extra_list_scrollbar_default.set_pad_top(6)
style_tool_ddlist_2_extra_list_scrollbar_default.set_pad_bottom(6)

# add style for tool_ddlist_2_list
tool_ddlist_2_list.add_style(style_tool_ddlist_2_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_tool_ddlist_2_main_main_default
style_tool_ddlist_2_main_main_default = lv.style_t()
style_tool_ddlist_2_main_main_default.init()
style_tool_ddlist_2_main_main_default.set_radius(3)
style_tool_ddlist_2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_tool_ddlist_2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_tool_ddlist_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_ddlist_2_main_main_default.set_bg_opa(255)
style_tool_ddlist_2_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_tool_ddlist_2_main_main_default.set_border_width(1)
style_tool_ddlist_2_main_main_default.set_border_opa(255)
style_tool_ddlist_2_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_tool_ddlist_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_ddlist_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_ddlist_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_ddlist_2_main_main_default.set_pad_left(6)
style_tool_ddlist_2_main_main_default.set_pad_right(6)
style_tool_ddlist_2_main_main_default.set_pad_top(8)

# add style for tool_ddlist_2
tool_ddlist_2.add_style(style_tool_ddlist_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_label_2 = lv.label(tool_cont_1)
tool_label_2.set_pos(int(9),int(75))
tool_label_2.set_size(62,22)
tool_label_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_label_2.set_text("Feed:")
tool_label_2.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_label_2_main_main_default
style_tool_label_2_main_main_default = lv.style_t()
style_tool_label_2_main_main_default.init()
style_tool_label_2_main_main_default.set_radius(0)
style_tool_label_2_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_label_2_main_main_default.set_bg_opa(0)
style_tool_label_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_label_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_label_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_label_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_label_2_main_main_default.set_text_letter_space(2)
style_tool_label_2_main_main_default.set_text_line_space(0)
style_tool_label_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_label_2_main_main_default.set_pad_left(0)
style_tool_label_2_main_main_default.set_pad_right(0)
style_tool_label_2_main_main_default.set_pad_top(0)
style_tool_label_2_main_main_default.set_pad_bottom(0)

# add style for tool_label_2
tool_label_2.add_style(style_tool_label_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_label_1 = lv.label(tool_cont_1)
tool_label_1.set_pos(int(13),int(23))
tool_label_1.set_size(54,25)
tool_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_label_1.set_text("Step:")
tool_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_label_1_main_main_default
style_tool_label_1_main_main_default = lv.style_t()
style_tool_label_1_main_main_default.init()
style_tool_label_1_main_main_default.set_radius(0)
style_tool_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_label_1_main_main_default.set_bg_opa(0)
style_tool_label_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_label_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_label_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_label_1_main_main_default.set_text_letter_space(2)
style_tool_label_1_main_main_default.set_text_line_space(0)
style_tool_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_label_1_main_main_default.set_pad_left(0)
style_tool_label_1_main_main_default.set_pad_right(0)
style_tool_label_1_main_main_default.set_pad_top(0)
style_tool_label_1_main_main_default.set_pad_bottom(0)

# add style for tool_label_1
tool_label_1.add_style(style_tool_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_cont_1_main_main_default
style_tool_cont_1_main_main_default = lv.style_t()
style_tool_cont_1_main_main_default.init()
style_tool_cont_1_main_main_default.set_radius(10)
style_tool_cont_1_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_tool_cont_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_cont_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_cont_1_main_main_default.set_bg_opa(255)
style_tool_cont_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_tool_cont_1_main_main_default.set_border_width(0)
style_tool_cont_1_main_main_default.set_border_opa(255)
style_tool_cont_1_main_main_default.set_pad_left(0)
style_tool_cont_1_main_main_default.set_pad_right(0)
style_tool_cont_1_main_main_default.set_pad_top(0)
style_tool_cont_1_main_main_default.set_pad_bottom(0)

# add style for tool_cont_1
tool_cont_1.add_style(style_tool_cont_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_ddlist_1 = lv.dropdown(tool)
tool_ddlist_1.set_pos(int(366),int(133))
tool_ddlist_1.set_size(66,27)
tool_ddlist_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_ddlist_1.set_options("1 mm\n5 mm\n10 mm")

tool_ddlist_1_list = tool_ddlist_1.get_list()
# create style style_tool_ddlist_1_extra_list_selected_checked
style_tool_ddlist_1_extra_list_selected_checked = lv.style_t()
style_tool_ddlist_1_extra_list_selected_checked.init()
style_tool_ddlist_1_extra_list_selected_checked.set_radius(3)
style_tool_ddlist_1_extra_list_selected_checked.set_bg_color(lv.color_make(0x00,0xa1,0xb5))
style_tool_ddlist_1_extra_list_selected_checked.set_bg_grad_color(lv.color_make(0x00,0xa1,0xb5))
style_tool_ddlist_1_extra_list_selected_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_ddlist_1_extra_list_selected_checked.set_bg_opa(255)
style_tool_ddlist_1_extra_list_selected_checked.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_tool_ddlist_1_extra_list_selected_checked.set_border_width(1)
style_tool_ddlist_1_extra_list_selected_checked.set_border_opa(255)
style_tool_ddlist_1_extra_list_selected_checked.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_tool_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_ddlist_1_extra_list_selected_checked.set_text_font(lv.font_montserrat_16)
style_tool_ddlist_1_extra_list_selected_checked.set_pad_left(6)
style_tool_ddlist_1_extra_list_selected_checked.set_pad_right(6)
style_tool_ddlist_1_extra_list_selected_checked.set_pad_top(6)
style_tool_ddlist_1_extra_list_selected_checked.set_pad_bottom(6)

# add style for tool_ddlist_1_list
tool_ddlist_1_list.add_style(style_tool_ddlist_1_extra_list_selected_checked, lv.PART.SELECTED|lv.STATE.CHECKED)

# create style style_tool_ddlist_1_extra_list_main_default
style_tool_ddlist_1_extra_list_main_default = lv.style_t()
style_tool_ddlist_1_extra_list_main_default.init()
style_tool_ddlist_1_extra_list_main_default.set_radius(3)
style_tool_ddlist_1_extra_list_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_tool_ddlist_1_extra_list_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_tool_ddlist_1_extra_list_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_ddlist_1_extra_list_main_default.set_bg_opa(255)
style_tool_ddlist_1_extra_list_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_tool_ddlist_1_extra_list_main_default.set_border_width(1)
style_tool_ddlist_1_extra_list_main_default.set_border_opa(255)
style_tool_ddlist_1_extra_list_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_tool_ddlist_1_extra_list_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_ddlist_1_extra_list_main_default.set_text_font(lv.font_montserrat_16)
style_tool_ddlist_1_extra_list_main_default.set_pad_left(6)
style_tool_ddlist_1_extra_list_main_default.set_pad_right(6)
style_tool_ddlist_1_extra_list_main_default.set_pad_top(6)
style_tool_ddlist_1_extra_list_main_default.set_pad_bottom(6)
style_tool_ddlist_1_extra_list_main_default.set_max_height(90)

# add style for tool_ddlist_1_list
tool_ddlist_1_list.add_style(style_tool_ddlist_1_extra_list_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_ddlist_1_extra_list_scrollbar_default
style_tool_ddlist_1_extra_list_scrollbar_default = lv.style_t()
style_tool_ddlist_1_extra_list_scrollbar_default.init()
style_tool_ddlist_1_extra_list_scrollbar_default.set_radius(3)
style_tool_ddlist_1_extra_list_scrollbar_default.set_bg_color(lv.color_make(0x00,0xff,0x00))
style_tool_ddlist_1_extra_list_scrollbar_default.set_bg_opa(255)
style_tool_ddlist_1_extra_list_scrollbar_default.set_pad_left(6)
style_tool_ddlist_1_extra_list_scrollbar_default.set_pad_right(6)
style_tool_ddlist_1_extra_list_scrollbar_default.set_pad_top(6)
style_tool_ddlist_1_extra_list_scrollbar_default.set_pad_bottom(6)

# add style for tool_ddlist_1_list
tool_ddlist_1_list.add_style(style_tool_ddlist_1_extra_list_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

# create style style_tool_ddlist_1_main_main_default
style_tool_ddlist_1_main_main_default = lv.style_t()
style_tool_ddlist_1_main_main_default.init()
style_tool_ddlist_1_main_main_default.set_radius(3)
style_tool_ddlist_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_tool_ddlist_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_tool_ddlist_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_ddlist_1_main_main_default.set_bg_opa(255)
style_tool_ddlist_1_main_main_default.set_border_color(lv.color_make(0xe1,0xe6,0xee))
style_tool_ddlist_1_main_main_default.set_border_width(1)
style_tool_ddlist_1_main_main_default.set_border_opa(255)
style_tool_ddlist_1_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_tool_ddlist_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_ddlist_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_ddlist_1_main_main_default.set_pad_left(6)
style_tool_ddlist_1_main_main_default.set_pad_right(6)
style_tool_ddlist_1_main_main_default.set_pad_top(8)

# add style for tool_ddlist_1
tool_ddlist_1.add_style(style_tool_ddlist_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_cont_2 = lv.obj(tool)
tool_cont_2.set_pos(int(37),int(56))
tool_cont_2.set_size(243,238)
tool_cont_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_tool_cont_2_main_main_default
style_tool_cont_2_main_main_default = lv.style_t()
style_tool_cont_2_main_main_default.init()
style_tool_cont_2_main_main_default.set_radius(0)
style_tool_cont_2_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_tool_cont_2_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_cont_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_cont_2_main_main_default.set_bg_opa(255)
style_tool_cont_2_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_tool_cont_2_main_main_default.set_border_width(0)
style_tool_cont_2_main_main_default.set_border_opa(255)
style_tool_cont_2_main_main_default.set_pad_left(0)
style_tool_cont_2_main_main_default.set_pad_right(0)
style_tool_cont_2_main_main_default.set_pad_top(0)
style_tool_cont_2_main_main_default.set_pad_bottom(0)

# add style for tool_cont_2
tool_cont_2.add_style(style_tool_cont_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_label_3 = lv.label(tool)
tool_label_3.set_pos(int(280),int(60))
tool_label_3.set_size(37,23)
tool_label_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_label_3.set_text("x:")
tool_label_3.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_label_3_main_main_default
style_tool_label_3_main_main_default = lv.style_t()
style_tool_label_3_main_main_default.init()
style_tool_label_3_main_main_default.set_radius(0)
style_tool_label_3_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_label_3_main_main_default.set_bg_opa(0)
style_tool_label_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_label_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_label_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_label_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_label_3_main_main_default.set_text_letter_space(2)
style_tool_label_3_main_main_default.set_text_line_space(0)
style_tool_label_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_label_3_main_main_default.set_pad_left(0)
style_tool_label_3_main_main_default.set_pad_right(0)
style_tool_label_3_main_main_default.set_pad_top(0)
style_tool_label_3_main_main_default.set_pad_bottom(0)

# add style for tool_label_3
tool_label_3.add_style(style_tool_label_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_label_4 = lv.label(tool)
tool_label_4.set_pos(int(351),int(60))
tool_label_4.set_size(37,23)
tool_label_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_label_4.set_text("y:")
tool_label_4.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_label_4_main_main_default
style_tool_label_4_main_main_default = lv.style_t()
style_tool_label_4_main_main_default.init()
style_tool_label_4_main_main_default.set_radius(0)
style_tool_label_4_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_4_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_label_4_main_main_default.set_bg_opa(0)
style_tool_label_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_label_4_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_label_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_label_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_label_4_main_main_default.set_text_letter_space(2)
style_tool_label_4_main_main_default.set_text_line_space(0)
style_tool_label_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_label_4_main_main_default.set_pad_left(0)
style_tool_label_4_main_main_default.set_pad_right(0)
style_tool_label_4_main_main_default.set_pad_top(0)
style_tool_label_4_main_main_default.set_pad_bottom(0)

# add style for tool_label_4
tool_label_4.add_style(style_tool_label_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_label_5 = lv.label(tool)
tool_label_5.set_pos(int(429),int(60))
tool_label_5.set_size(37,23)
tool_label_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tool_label_5.set_text("z:")
tool_label_5.set_long_mode(lv.label.LONG.WRAP)
# create style style_tool_label_5_main_main_default
style_tool_label_5_main_main_default = lv.style_t()
style_tool_label_5_main_main_default.init()
style_tool_label_5_main_main_default.set_radius(0)
style_tool_label_5_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_5_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_label_5_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_label_5_main_main_default.set_bg_opa(0)
style_tool_label_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_label_5_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_label_5_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_label_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_label_5_main_main_default.set_text_letter_space(2)
style_tool_label_5_main_main_default.set_text_line_space(0)
style_tool_label_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_label_5_main_main_default.set_pad_left(0)
style_tool_label_5_main_main_default.set_pad_right(0)
style_tool_label_5_main_main_default.set_pad_top(0)
style_tool_label_5_main_main_default.set_pad_bottom(0)

# add style for tool_label_5
tool_label_5.add_style(style_tool_label_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_imgbtn_tool_return = lv.imgbtn(tool)
tool_imgbtn_tool_return.set_pos(int(15),int(23))
tool_imgbtn_tool_return.set_size(72,22)
tool_imgbtn_tool_return.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-428528871.png','rb') as f:
        tool_imgbtn_tool_return_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-428528871.png')
    sys.exit()

tool_imgbtn_tool_return_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_tool_return_imgReleased_data),
  'header': {'always_zero': 0, 'w': 72, 'h': 22, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_tool_return_imgReleased_data
})
tool_imgbtn_tool_return.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_tool_return_imgReleased, None, None)





tool_imgbtn_tool_return.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_tool_return_main_main_default
style_tool_imgbtn_tool_return_main_main_default = lv.style_t()
style_tool_imgbtn_tool_return_main_main_default.init()
style_tool_imgbtn_tool_return_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_tool_return_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_tool_return_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_tool_return_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_tool_return_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_tool_return_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_tool_return_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_tool_return_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_tool_return
tool_imgbtn_tool_return.add_style(style_tool_imgbtn_tool_return_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_tool_return_main_main_pressed
style_tool_imgbtn_tool_return_main_main_pressed = lv.style_t()
style_tool_imgbtn_tool_return_main_main_pressed.init()
style_tool_imgbtn_tool_return_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_tool_return_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_tool_return_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_tool_return_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_tool_return_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_tool_return_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_tool_return_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_tool_return_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_tool_return
tool_imgbtn_tool_return.add_style(style_tool_imgbtn_tool_return_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_tool_return_main_main_checked
style_tool_imgbtn_tool_return_main_main_checked = lv.style_t()
style_tool_imgbtn_tool_return_main_main_checked.init()
style_tool_imgbtn_tool_return_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_tool_return_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_tool_return_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_tool_return_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_tool_return_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_tool_return_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_tool_return_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_tool_return_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_tool_return
tool_imgbtn_tool_return.add_style(style_tool_imgbtn_tool_return_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_cont_3 = lv.obj(tool)
tool_cont_3.set_pos(int(292),int(250))
tool_cont_3.set_size(166,48)
tool_cont_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_tool_cont_3_main_main_default
style_tool_cont_3_main_main_default = lv.style_t()
style_tool_cont_3_main_main_default.init()
style_tool_cont_3_main_main_default.set_radius(0)
style_tool_cont_3_main_main_default.set_bg_color(lv.color_make(0xf5,0xf5,0xf5))
style_tool_cont_3_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_tool_cont_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_tool_cont_3_main_main_default.set_bg_opa(255)
style_tool_cont_3_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_tool_cont_3_main_main_default.set_border_width(0)
style_tool_cont_3_main_main_default.set_border_opa(255)
style_tool_cont_3_main_main_default.set_pad_left(0)
style_tool_cont_3_main_main_default.set_pad_right(0)
style_tool_cont_3_main_main_default.set_pad_top(0)
style_tool_cont_3_main_main_default.set_pad_bottom(0)

# add style for tool_cont_3
tool_cont_3.add_style(style_tool_cont_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

tool_imgbtn_2 = lv.imgbtn(tool)
tool_imgbtn_2.set_pos(int(96),int(76))
tool_imgbtn_2.set_size(50,50)
tool_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1952900255.png','rb') as f:
        tool_imgbtn_2_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1952900255.png')
    sys.exit()

tool_imgbtn_2_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_2_imgReleased_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_2_imgReleased_data
})
tool_imgbtn_2.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_2_imgReleased, None, None)





tool_imgbtn_2.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_2_main_main_default
style_tool_imgbtn_2_main_main_default = lv.style_t()
style_tool_imgbtn_2_main_main_default.init()
style_tool_imgbtn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_2_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_2
tool_imgbtn_2.add_style(style_tool_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_2_main_main_pressed
style_tool_imgbtn_2_main_main_pressed = lv.style_t()
style_tool_imgbtn_2_main_main_pressed.init()
style_tool_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_2_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_2_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_2
tool_imgbtn_2.add_style(style_tool_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_2_main_main_checked
style_tool_imgbtn_2_main_main_checked = lv.style_t()
style_tool_imgbtn_2_main_main_checked.init()
style_tool_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_2_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_2_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_2
tool_imgbtn_2.add_style(style_tool_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_3 = lv.imgbtn(tool)
tool_imgbtn_3.set_pos(int(37),int(148))
tool_imgbtn_3.set_size(50,50)
tool_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-661691765.png','rb') as f:
        tool_imgbtn_3_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-661691765.png')
    sys.exit()

tool_imgbtn_3_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_3_imgReleased_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_3_imgReleased_data
})
tool_imgbtn_3.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_3_imgReleased, None, None)





tool_imgbtn_3.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_3_main_main_default
style_tool_imgbtn_3_main_main_default = lv.style_t()
style_tool_imgbtn_3_main_main_default.init()
style_tool_imgbtn_3_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_3_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_3
tool_imgbtn_3.add_style(style_tool_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_3_main_main_pressed
style_tool_imgbtn_3_main_main_pressed = lv.style_t()
style_tool_imgbtn_3_main_main_pressed.init()
style_tool_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_3_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_3_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_3
tool_imgbtn_3.add_style(style_tool_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_3_main_main_checked
style_tool_imgbtn_3_main_main_checked = lv.style_t()
style_tool_imgbtn_3_main_main_checked.init()
style_tool_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_3_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_3_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_3
tool_imgbtn_3.add_style(style_tool_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_4 = lv.imgbtn(tool)
tool_imgbtn_4.set_pos(int(157),int(148))
tool_imgbtn_4.set_size(50,50)
tool_imgbtn_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp519161892.png','rb') as f:
        tool_imgbtn_4_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp519161892.png')
    sys.exit()

tool_imgbtn_4_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_4_imgReleased_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_4_imgReleased_data
})
tool_imgbtn_4.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_4_imgReleased, None, None)





tool_imgbtn_4.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_4_main_main_default
style_tool_imgbtn_4_main_main_default = lv.style_t()
style_tool_imgbtn_4_main_main_default.init()
style_tool_imgbtn_4_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_4_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_4_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_4_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_4_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_4
tool_imgbtn_4.add_style(style_tool_imgbtn_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_4_main_main_pressed
style_tool_imgbtn_4_main_main_pressed = lv.style_t()
style_tool_imgbtn_4_main_main_pressed.init()
style_tool_imgbtn_4_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_4_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_4_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_4_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_4_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_4_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_4_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_4_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_4
tool_imgbtn_4.add_style(style_tool_imgbtn_4_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_4_main_main_checked
style_tool_imgbtn_4_main_main_checked = lv.style_t()
style_tool_imgbtn_4_main_main_checked.init()
style_tool_imgbtn_4_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_4_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_4_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_4_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_4_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_4_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_4_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_4_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_4
tool_imgbtn_4.add_style(style_tool_imgbtn_4_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_6 = lv.imgbtn(tool)
tool_imgbtn_6.set_pos(int(207),int(83))
tool_imgbtn_6.set_size(50,50)
tool_imgbtn_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-1223553020.png','rb') as f:
        tool_imgbtn_6_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-1223553020.png')
    sys.exit()

tool_imgbtn_6_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_6_imgReleased_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_6_imgReleased_data
})
tool_imgbtn_6.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_6_imgReleased, None, None)





tool_imgbtn_6.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_6_main_main_default
style_tool_imgbtn_6_main_main_default = lv.style_t()
style_tool_imgbtn_6_main_main_default.init()
style_tool_imgbtn_6_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_6_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_6_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_6_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_6_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_6_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_6_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_6_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_6
tool_imgbtn_6.add_style(style_tool_imgbtn_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_6_main_main_pressed
style_tool_imgbtn_6_main_main_pressed = lv.style_t()
style_tool_imgbtn_6_main_main_pressed.init()
style_tool_imgbtn_6_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_6_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_6_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_6_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_6_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_6_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_6_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_6_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_6
tool_imgbtn_6.add_style(style_tool_imgbtn_6_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_6_main_main_checked
style_tool_imgbtn_6_main_main_checked = lv.style_t()
style_tool_imgbtn_6_main_main_checked.init()
style_tool_imgbtn_6_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_6_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_6_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_6_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_6_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_6_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_6_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_6_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_6
tool_imgbtn_6.add_style(style_tool_imgbtn_6_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_7 = lv.imgbtn(tool)
tool_imgbtn_7.set_pos(int(207),int(212))
tool_imgbtn_7.set_size(50,50)
tool_imgbtn_7.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-636720053.png','rb') as f:
        tool_imgbtn_7_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-636720053.png')
    sys.exit()

tool_imgbtn_7_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_7_imgReleased_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_7_imgReleased_data
})
tool_imgbtn_7.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_7_imgReleased, None, None)





tool_imgbtn_7.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_7_main_main_default
style_tool_imgbtn_7_main_main_default = lv.style_t()
style_tool_imgbtn_7_main_main_default.init()
style_tool_imgbtn_7_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_7_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_7_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_7_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_7_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_7_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_7_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_7_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_7
tool_imgbtn_7.add_style(style_tool_imgbtn_7_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_7_main_main_pressed
style_tool_imgbtn_7_main_main_pressed = lv.style_t()
style_tool_imgbtn_7_main_main_pressed.init()
style_tool_imgbtn_7_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_7_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_7_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_7_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_7_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_7_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_7_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_7_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_7
tool_imgbtn_7.add_style(style_tool_imgbtn_7_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_7_main_main_checked
style_tool_imgbtn_7_main_main_checked = lv.style_t()
style_tool_imgbtn_7_main_main_checked.init()
style_tool_imgbtn_7_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_7_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_7_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_7_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_7_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_7_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_7_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_7_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_7
tool_imgbtn_7.add_style(style_tool_imgbtn_7_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_5 = lv.imgbtn(tool)
tool_imgbtn_5.set_pos(int(87),int(212))
tool_imgbtn_5.set_size(50,50)
tool_imgbtn_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-1786870234.png','rb') as f:
        tool_imgbtn_5_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-1786870234.png')
    sys.exit()

tool_imgbtn_5_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_5_imgReleased_data),
  'header': {'always_zero': 0, 'w': 50, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_5_imgReleased_data
})
tool_imgbtn_5.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_5_imgReleased, None, None)





tool_imgbtn_5.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_5_main_main_default
style_tool_imgbtn_5_main_main_default = lv.style_t()
style_tool_imgbtn_5_main_main_default.init()
style_tool_imgbtn_5_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_5_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_5_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_5_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_5_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_5_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_5_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_5_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_5
tool_imgbtn_5.add_style(style_tool_imgbtn_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_5_main_main_pressed
style_tool_imgbtn_5_main_main_pressed = lv.style_t()
style_tool_imgbtn_5_main_main_pressed.init()
style_tool_imgbtn_5_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_5_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_5_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_5_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_5_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_5_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_5_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_5_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_5
tool_imgbtn_5.add_style(style_tool_imgbtn_5_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_5_main_main_checked
style_tool_imgbtn_5_main_main_checked = lv.style_t()
style_tool_imgbtn_5_main_main_checked.init()
style_tool_imgbtn_5_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_5_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_5_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_5_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_5_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_5_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_5_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_5_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_5
tool_imgbtn_5.add_style(style_tool_imgbtn_5_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_8 = lv.imgbtn(tool)
tool_imgbtn_8.set_pos(int(298),int(262))
tool_imgbtn_8.set_size(30,30)
tool_imgbtn_8.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-1801857963.png','rb') as f:
        tool_imgbtn_8_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-1801857963.png')
    sys.exit()

tool_imgbtn_8_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_8_imgReleased_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_8_imgReleased_data
})
tool_imgbtn_8.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_8_imgReleased, None, None)





tool_imgbtn_8.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_8_main_main_default
style_tool_imgbtn_8_main_main_default = lv.style_t()
style_tool_imgbtn_8_main_main_default.init()
style_tool_imgbtn_8_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_8_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_8_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_8_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_8_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_8_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_8_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_8_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_8
tool_imgbtn_8.add_style(style_tool_imgbtn_8_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_8_main_main_pressed
style_tool_imgbtn_8_main_main_pressed = lv.style_t()
style_tool_imgbtn_8_main_main_pressed.init()
style_tool_imgbtn_8_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_8_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_8_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_8_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_8_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_8_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_8_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_8_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_8
tool_imgbtn_8.add_style(style_tool_imgbtn_8_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_8_main_main_checked
style_tool_imgbtn_8_main_main_checked = lv.style_t()
style_tool_imgbtn_8_main_main_checked.init()
style_tool_imgbtn_8_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_8_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_8_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_8_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_8_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_8_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_8_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_8_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_8
tool_imgbtn_8.add_style(style_tool_imgbtn_8_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_9 = lv.imgbtn(tool)
tool_imgbtn_9.set_pos(int(336),int(262))
tool_imgbtn_9.set_size(30,30)
tool_imgbtn_9.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp752139568.png','rb') as f:
        tool_imgbtn_9_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp752139568.png')
    sys.exit()

tool_imgbtn_9_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_9_imgReleased_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_9_imgReleased_data
})
tool_imgbtn_9.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_9_imgReleased, None, None)





tool_imgbtn_9.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_9_main_main_default
style_tool_imgbtn_9_main_main_default = lv.style_t()
style_tool_imgbtn_9_main_main_default.init()
style_tool_imgbtn_9_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_9_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_9_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_9_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_9_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_9_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_9_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_9_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_9
tool_imgbtn_9.add_style(style_tool_imgbtn_9_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_9_main_main_pressed
style_tool_imgbtn_9_main_main_pressed = lv.style_t()
style_tool_imgbtn_9_main_main_pressed.init()
style_tool_imgbtn_9_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_9_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_9_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_9_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_9_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_9_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_9_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_9_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_9
tool_imgbtn_9.add_style(style_tool_imgbtn_9_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_9_main_main_checked
style_tool_imgbtn_9_main_main_checked = lv.style_t()
style_tool_imgbtn_9_main_main_checked.init()
style_tool_imgbtn_9_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_9_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_9_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_9_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_9_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_9_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_9_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_9_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_9
tool_imgbtn_9.add_style(style_tool_imgbtn_9_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_10 = lv.imgbtn(tool)
tool_imgbtn_10.set_pos(int(376),int(262))
tool_imgbtn_10.set_size(30,30)
tool_imgbtn_10.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-1386149477.png','rb') as f:
        tool_imgbtn_10_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-1386149477.png')
    sys.exit()

tool_imgbtn_10_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_10_imgReleased_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_10_imgReleased_data
})
tool_imgbtn_10.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_10_imgReleased, None, None)





tool_imgbtn_10.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_10_main_main_default
style_tool_imgbtn_10_main_main_default = lv.style_t()
style_tool_imgbtn_10_main_main_default.init()
style_tool_imgbtn_10_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_10_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_10_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_10_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_10_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_10_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_10_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_10_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_10
tool_imgbtn_10.add_style(style_tool_imgbtn_10_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_10_main_main_pressed
style_tool_imgbtn_10_main_main_pressed = lv.style_t()
style_tool_imgbtn_10_main_main_pressed.init()
style_tool_imgbtn_10_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_10_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_10_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_10_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_10_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_10_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_10_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_10_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_10
tool_imgbtn_10.add_style(style_tool_imgbtn_10_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_10_main_main_checked
style_tool_imgbtn_10_main_main_checked = lv.style_t()
style_tool_imgbtn_10_main_main_checked.init()
style_tool_imgbtn_10_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_10_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_10_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_10_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_10_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_10_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_10_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_10_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_10
tool_imgbtn_10.add_style(style_tool_imgbtn_10_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tool_imgbtn_11 = lv.imgbtn(tool)
tool_imgbtn_11.set_pos(int(416),int(262))
tool_imgbtn_11.set_size(30,30)
tool_imgbtn_11.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp303295155.png','rb') as f:
        tool_imgbtn_11_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp303295155.png')
    sys.exit()

tool_imgbtn_11_imgReleased = lv.img_dsc_t({
  'data_size': len(tool_imgbtn_11_imgReleased_data),
  'header': {'always_zero': 0, 'w': 30, 'h': 30, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': tool_imgbtn_11_imgReleased_data
})
tool_imgbtn_11.set_src(lv.imgbtn.STATE.RELEASED, tool_imgbtn_11_imgReleased, None, None)





tool_imgbtn_11.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_tool_imgbtn_11_main_main_default
style_tool_imgbtn_11_main_main_default = lv.style_t()
style_tool_imgbtn_11_main_main_default.init()
style_tool_imgbtn_11_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_tool_imgbtn_11_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_11_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_11_main_main_default.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_11_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_11_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_tool_imgbtn_11_main_main_default.set_img_recolor_opa(0)
style_tool_imgbtn_11_main_main_default.set_img_opa(255)

# add style for tool_imgbtn_11
tool_imgbtn_11.add_style(style_tool_imgbtn_11_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_tool_imgbtn_11_main_main_pressed
style_tool_imgbtn_11_main_main_pressed = lv.style_t()
style_tool_imgbtn_11_main_main_pressed.init()
style_tool_imgbtn_11_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_11_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_11_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_11_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_11_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_11_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_11_main_main_pressed.set_img_recolor_opa(0)
style_tool_imgbtn_11_main_main_pressed.set_img_opa(255)

# add style for tool_imgbtn_11
tool_imgbtn_11.add_style(style_tool_imgbtn_11_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_tool_imgbtn_11_main_main_checked
style_tool_imgbtn_11_main_main_checked = lv.style_t()
style_tool_imgbtn_11_main_main_checked.init()
style_tool_imgbtn_11_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_tool_imgbtn_11_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_tool_imgbtn_11_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_tool_imgbtn_11_main_main_checked.set_text_font(lv.font_montserrat_16)
style_tool_imgbtn_11_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_tool_imgbtn_11_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_tool_imgbtn_11_main_main_checked.set_img_recolor_opa(0)
style_tool_imgbtn_11_main_main_checked.set_img_opa(255)

# add style for tool_imgbtn_11
tool_imgbtn_11.add_style(style_tool_imgbtn_11_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

larse_power = lv.obj()
larse_power.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_larse_power_main_main_default
style_larse_power_main_main_default = lv.style_t()
style_larse_power_main_main_default.init()
style_larse_power_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_main_main_default.set_bg_opa(255)

# add style for larse_power
larse_power.add_style(style_larse_power_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

larse_power_imgbtn_larsepower_return = lv.imgbtn(larse_power)
larse_power_imgbtn_larsepower_return.set_pos(int(24),int(16))
larse_power_imgbtn_larsepower_return.set_size(82,42)
larse_power_imgbtn_larsepower_return.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1463469494.png','rb') as f:
        larse_power_imgbtn_larsepower_return_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1463469494.png')
    sys.exit()

larse_power_imgbtn_larsepower_return_imgReleased = lv.img_dsc_t({
  'data_size': len(larse_power_imgbtn_larsepower_return_imgReleased_data),
  'header': {'always_zero': 0, 'w': 82, 'h': 42, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': larse_power_imgbtn_larsepower_return_imgReleased_data
})
larse_power_imgbtn_larsepower_return.set_src(lv.imgbtn.STATE.RELEASED, larse_power_imgbtn_larsepower_return_imgReleased, None, None)





larse_power_imgbtn_larsepower_return.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_larse_power_imgbtn_larsepower_return_main_main_default
style_larse_power_imgbtn_larsepower_return_main_main_default = lv.style_t()
style_larse_power_imgbtn_larsepower_return_main_main_default.init()
style_larse_power_imgbtn_larsepower_return_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_larse_power_imgbtn_larsepower_return_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_larse_power_imgbtn_larsepower_return_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_larse_power_imgbtn_larsepower_return_main_main_default.set_text_font(lv.font_montserrat_16)
style_larse_power_imgbtn_larsepower_return_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_larse_power_imgbtn_larsepower_return_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_larse_power_imgbtn_larsepower_return_main_main_default.set_img_recolor_opa(0)
style_larse_power_imgbtn_larsepower_return_main_main_default.set_img_opa(255)

# add style for larse_power_imgbtn_larsepower_return
larse_power_imgbtn_larsepower_return.add_style(style_larse_power_imgbtn_larsepower_return_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_larse_power_imgbtn_larsepower_return_main_main_pressed
style_larse_power_imgbtn_larsepower_return_main_main_pressed = lv.style_t()
style_larse_power_imgbtn_larsepower_return_main_main_pressed.init()
style_larse_power_imgbtn_larsepower_return_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_larse_power_imgbtn_larsepower_return_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_larse_power_imgbtn_larsepower_return_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_larse_power_imgbtn_larsepower_return_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_larse_power_imgbtn_larsepower_return_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_larse_power_imgbtn_larsepower_return_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_larse_power_imgbtn_larsepower_return_main_main_pressed.set_img_recolor_opa(0)
style_larse_power_imgbtn_larsepower_return_main_main_pressed.set_img_opa(255)

# add style for larse_power_imgbtn_larsepower_return
larse_power_imgbtn_larsepower_return.add_style(style_larse_power_imgbtn_larsepower_return_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_larse_power_imgbtn_larsepower_return_main_main_checked
style_larse_power_imgbtn_larsepower_return_main_main_checked = lv.style_t()
style_larse_power_imgbtn_larsepower_return_main_main_checked.init()
style_larse_power_imgbtn_larsepower_return_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_larse_power_imgbtn_larsepower_return_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_larse_power_imgbtn_larsepower_return_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_larse_power_imgbtn_larsepower_return_main_main_checked.set_text_font(lv.font_montserrat_16)
style_larse_power_imgbtn_larsepower_return_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_larse_power_imgbtn_larsepower_return_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_larse_power_imgbtn_larsepower_return_main_main_checked.set_img_recolor_opa(0)
style_larse_power_imgbtn_larsepower_return_main_main_checked.set_img_opa(255)

# add style for larse_power_imgbtn_larsepower_return
larse_power_imgbtn_larsepower_return.add_style(style_larse_power_imgbtn_larsepower_return_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

larse_power_label_1 = lv.label(larse_power)
larse_power_label_1.set_pos(int(54),int(83))
larse_power_label_1.set_size(149,29)
larse_power_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
larse_power_label_1.set_text("Larse Power Off")
larse_power_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_larse_power_label_1_main_main_default
style_larse_power_label_1_main_main_default = lv.style_t()
style_larse_power_label_1_main_main_default.init()
style_larse_power_label_1_main_main_default.set_radius(0)
style_larse_power_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_label_1_main_main_default.set_bg_opa(0)
style_larse_power_label_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_larse_power_label_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_larse_power_label_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_larse_power_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_larse_power_label_1_main_main_default.set_text_letter_space(2)
style_larse_power_label_1_main_main_default.set_text_line_space(0)
style_larse_power_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_larse_power_label_1_main_main_default.set_pad_left(0)
style_larse_power_label_1_main_main_default.set_pad_right(0)
style_larse_power_label_1_main_main_default.set_pad_top(0)
style_larse_power_label_1_main_main_default.set_pad_bottom(0)

# add style for larse_power_label_1
larse_power_label_1.add_style(style_larse_power_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

larse_power_sw_1 = lv.switch(larse_power)
larse_power_sw_1.set_pos(int(315),int(80))
larse_power_sw_1.set_size(40,20)
larse_power_sw_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_larse_power_sw_1_main_main_default
style_larse_power_sw_1_main_main_default = lv.style_t()
style_larse_power_sw_1_main_main_default.init()
style_larse_power_sw_1_main_main_default.set_radius(100)
style_larse_power_sw_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe2,0xe6))
style_larse_power_sw_1_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe2,0xe6))
style_larse_power_sw_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_sw_1_main_main_default.set_bg_opa(255)
style_larse_power_sw_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_sw_1_main_main_default.set_border_width(0)
style_larse_power_sw_1_main_main_default.set_border_opa(255)

# add style for larse_power_sw_1
larse_power_sw_1.add_style(style_larse_power_sw_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_larse_power_sw_1_main_indicator_checked
style_larse_power_sw_1_main_indicator_checked = lv.style_t()
style_larse_power_sw_1_main_indicator_checked.init()
style_larse_power_sw_1_main_indicator_checked.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_sw_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_sw_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_sw_1_main_indicator_checked.set_bg_opa(255)
style_larse_power_sw_1_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_sw_1_main_indicator_checked.set_border_width(0)
style_larse_power_sw_1_main_indicator_checked.set_border_opa(255)

# add style for larse_power_sw_1
larse_power_sw_1.add_style(style_larse_power_sw_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_larse_power_sw_1_main_knob_default
style_larse_power_sw_1_main_knob_default = lv.style_t()
style_larse_power_sw_1_main_knob_default.init()
style_larse_power_sw_1_main_knob_default.set_radius(100)
style_larse_power_sw_1_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_sw_1_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_sw_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_sw_1_main_knob_default.set_bg_opa(255)
style_larse_power_sw_1_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_sw_1_main_knob_default.set_border_width(0)
style_larse_power_sw_1_main_knob_default.set_border_opa(255)

# add style for larse_power_sw_1
larse_power_sw_1.add_style(style_larse_power_sw_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

larse_power_img_1 = lv.img(larse_power)
larse_power_img_1.set_pos(int(88),int(100))
larse_power_img_1.set_size(47,37)
larse_power_img_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
larse_power_img_1.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp106278068.png','rb') as f:
        larse_power_img_1_img_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp106278068.png')
    sys.exit()

larse_power_img_1_img = lv.img_dsc_t({
  'data_size': len(larse_power_img_1_img_data),
  'header': {'always_zero': 0, 'w': 47, 'h': 37, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': larse_power_img_1_img_data
})

larse_power_img_1.set_src(larse_power_img_1_img)
larse_power_img_1.set_pivot(0,0)
larse_power_img_1.set_angle(0)
# create style style_larse_power_img_1_main_main_default
style_larse_power_img_1_main_main_default = lv.style_t()
style_larse_power_img_1_main_main_default.init()
style_larse_power_img_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_larse_power_img_1_main_main_default.set_img_recolor_opa(0)
style_larse_power_img_1_main_main_default.set_img_opa(255)

# add style for larse_power_img_1
larse_power_img_1.add_style(style_larse_power_img_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

larse_power_img_2 = lv.img(larse_power)
larse_power_img_2.set_pos(int(90),int(139))
larse_power_img_2.set_size(44,44)
larse_power_img_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
larse_power_img_2.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp53024791.png','rb') as f:
        larse_power_img_2_img_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp53024791.png')
    sys.exit()

larse_power_img_2_img = lv.img_dsc_t({
  'data_size': len(larse_power_img_2_img_data),
  'header': {'always_zero': 0, 'w': 44, 'h': 44, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': larse_power_img_2_img_data
})

larse_power_img_2.set_src(larse_power_img_2_img)
larse_power_img_2.set_pivot(0,0)
larse_power_img_2.set_angle(0)
# create style style_larse_power_img_2_main_main_default
style_larse_power_img_2_main_main_default = lv.style_t()
style_larse_power_img_2_main_main_default.init()
style_larse_power_img_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_larse_power_img_2_main_main_default.set_img_recolor_opa(0)
style_larse_power_img_2_main_main_default.set_img_opa(255)

# add style for larse_power_img_2
larse_power_img_2.add_style(style_larse_power_img_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

larse_power_img_3 = lv.img(larse_power)
larse_power_img_3.set_pos(int(90),int(185))
larse_power_img_3.set_size(44,46)
larse_power_img_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
larse_power_img_3.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp279026313.png','rb') as f:
        larse_power_img_3_img_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp279026313.png')
    sys.exit()

larse_power_img_3_img = lv.img_dsc_t({
  'data_size': len(larse_power_img_3_img_data),
  'header': {'always_zero': 0, 'w': 44, 'h': 46, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': larse_power_img_3_img_data
})

larse_power_img_3.set_src(larse_power_img_3_img)
larse_power_img_3.set_pivot(0,0)
larse_power_img_3.set_angle(0)
# create style style_larse_power_img_3_main_main_default
style_larse_power_img_3_main_main_default = lv.style_t()
style_larse_power_img_3_main_main_default.init()
style_larse_power_img_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_larse_power_img_3_main_main_default.set_img_recolor_opa(0)
style_larse_power_img_3_main_main_default.set_img_opa(255)

# add style for larse_power_img_3
larse_power_img_3.add_style(style_larse_power_img_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

larse_power_img_4 = lv.img(larse_power)
larse_power_img_4.set_pos(int(88),int(231))
larse_power_img_4.set_size(46,47)
larse_power_img_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
larse_power_img_4.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1849825614.png','rb') as f:
        larse_power_img_4_img_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1849825614.png')
    sys.exit()

larse_power_img_4_img = lv.img_dsc_t({
  'data_size': len(larse_power_img_4_img_data),
  'header': {'always_zero': 0, 'w': 46, 'h': 47, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': larse_power_img_4_img_data
})

larse_power_img_4.set_src(larse_power_img_4_img)
larse_power_img_4.set_pivot(0,0)
larse_power_img_4.set_angle(0)
# create style style_larse_power_img_4_main_main_default
style_larse_power_img_4_main_main_default = lv.style_t()
style_larse_power_img_4_main_main_default.init()
style_larse_power_img_4_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_larse_power_img_4_main_main_default.set_img_recolor_opa(0)
style_larse_power_img_4_main_main_default.set_img_opa(255)

# add style for larse_power_img_4
larse_power_img_4.add_style(style_larse_power_img_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

larse_power_cb_1 = lv.checkbox(larse_power)
larse_power_cb_1.set_pos(int(325),int(110))
larse_power_cb_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_larse_power_cb_1_main_main_default
style_larse_power_cb_1_main_main_default = lv.style_t()
style_larse_power_cb_1_main_main_default.init()
style_larse_power_cb_1_main_main_default.set_radius(6)
style_larse_power_cb_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_cb_1_main_main_default.set_bg_opa(0)
style_larse_power_cb_1_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_larse_power_cb_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_larse_power_cb_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_larse_power_cb_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_larse_power_cb_1_main_main_default.set_text_letter_space(2)

# add style for larse_power_cb_1
larse_power_cb_1.add_style(style_larse_power_cb_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_larse_power_cb_1_main_indicator_default
style_larse_power_cb_1_main_indicator_default = lv.style_t()
style_larse_power_cb_1_main_indicator_default.init()
style_larse_power_cb_1_main_indicator_default.set_radius(6)
style_larse_power_cb_1_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_1_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_1_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_cb_1_main_indicator_default.set_bg_opa(255)
style_larse_power_cb_1_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_cb_1_main_indicator_default.set_border_width(2)
style_larse_power_cb_1_main_indicator_default.set_border_opa(255)

# add style for larse_power_cb_1
larse_power_cb_1.add_style(style_larse_power_cb_1_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

larse_power_cb_2 = lv.checkbox(larse_power)
larse_power_cb_2.set_pos(int(325),int(152))
larse_power_cb_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_larse_power_cb_2_main_main_default
style_larse_power_cb_2_main_main_default = lv.style_t()
style_larse_power_cb_2_main_main_default.init()
style_larse_power_cb_2_main_main_default.set_radius(6)
style_larse_power_cb_2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_cb_2_main_main_default.set_bg_opa(0)
style_larse_power_cb_2_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_larse_power_cb_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_larse_power_cb_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_larse_power_cb_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_larse_power_cb_2_main_main_default.set_text_letter_space(2)

# add style for larse_power_cb_2
larse_power_cb_2.add_style(style_larse_power_cb_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_larse_power_cb_2_main_indicator_default
style_larse_power_cb_2_main_indicator_default = lv.style_t()
style_larse_power_cb_2_main_indicator_default.init()
style_larse_power_cb_2_main_indicator_default.set_radius(6)
style_larse_power_cb_2_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_2_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_2_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_cb_2_main_indicator_default.set_bg_opa(255)
style_larse_power_cb_2_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_cb_2_main_indicator_default.set_border_width(2)
style_larse_power_cb_2_main_indicator_default.set_border_opa(255)

# add style for larse_power_cb_2
larse_power_cb_2.add_style(style_larse_power_cb_2_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

larse_power_cb_3 = lv.checkbox(larse_power)
larse_power_cb_3.set_pos(int(325),int(200))
larse_power_cb_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_larse_power_cb_3_main_main_default
style_larse_power_cb_3_main_main_default = lv.style_t()
style_larse_power_cb_3_main_main_default.init()
style_larse_power_cb_3_main_main_default.set_radius(6)
style_larse_power_cb_3_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_3_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_3_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_cb_3_main_main_default.set_bg_opa(0)
style_larse_power_cb_3_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_larse_power_cb_3_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_larse_power_cb_3_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_larse_power_cb_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_larse_power_cb_3_main_main_default.set_text_letter_space(2)

# add style for larse_power_cb_3
larse_power_cb_3.add_style(style_larse_power_cb_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_larse_power_cb_3_main_indicator_default
style_larse_power_cb_3_main_indicator_default = lv.style_t()
style_larse_power_cb_3_main_indicator_default.init()
style_larse_power_cb_3_main_indicator_default.set_radius(6)
style_larse_power_cb_3_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_3_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_3_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_cb_3_main_indicator_default.set_bg_opa(255)
style_larse_power_cb_3_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_cb_3_main_indicator_default.set_border_width(2)
style_larse_power_cb_3_main_indicator_default.set_border_opa(255)

# add style for larse_power_cb_3
larse_power_cb_3.add_style(style_larse_power_cb_3_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

larse_power_cb_4 = lv.checkbox(larse_power)
larse_power_cb_4.set_pos(int(325),int(246))
larse_power_cb_4.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_larse_power_cb_4_main_main_default
style_larse_power_cb_4_main_main_default = lv.style_t()
style_larse_power_cb_4_main_main_default.init()
style_larse_power_cb_4_main_main_default.set_radius(6)
style_larse_power_cb_4_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_4_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_4_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_cb_4_main_main_default.set_bg_opa(0)
style_larse_power_cb_4_main_main_default.set_text_color(lv.color_make(0x0D,0x30,0x55))
try:
    style_larse_power_cb_4_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_larse_power_cb_4_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_larse_power_cb_4_main_main_default.set_text_font(lv.font_montserrat_16)
style_larse_power_cb_4_main_main_default.set_text_letter_space(2)

# add style for larse_power_cb_4
larse_power_cb_4.add_style(style_larse_power_cb_4_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_larse_power_cb_4_main_indicator_default
style_larse_power_cb_4_main_indicator_default = lv.style_t()
style_larse_power_cb_4_main_indicator_default.init()
style_larse_power_cb_4_main_indicator_default.set_radius(6)
style_larse_power_cb_4_main_indicator_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_4_main_indicator_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_larse_power_cb_4_main_indicator_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_larse_power_cb_4_main_indicator_default.set_bg_opa(255)
style_larse_power_cb_4_main_indicator_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_larse_power_cb_4_main_indicator_default.set_border_width(2)
style_larse_power_cb_4_main_indicator_default.set_border_opa(255)

# add style for larse_power_cb_4
larse_power_cb_4.add_style(style_larse_power_cb_4_main_indicator_default, lv.PART.INDICATOR|lv.STATE.DEFAULT)

sculpture = lv.obj()
sculpture.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_sculpture_main_main_default
style_sculpture_main_main_default = lv.style_t()
style_sculpture_main_main_default.init()
style_sculpture_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_sculpture_main_main_default.set_bg_opa(255)

# add style for sculpture
sculpture.add_style(style_sculpture_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

sculpture_imgbtn_sculpture_return = lv.imgbtn(sculpture)
sculpture_imgbtn_sculpture_return.set_pos(int(6),int(11))
sculpture_imgbtn_sculpture_return.set_size(100,50)
sculpture_imgbtn_sculpture_return.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1235204120.png','rb') as f:
        sculpture_imgbtn_sculpture_return_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1235204120.png')
    sys.exit()

sculpture_imgbtn_sculpture_return_imgReleased = lv.img_dsc_t({
  'data_size': len(sculpture_imgbtn_sculpture_return_imgReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sculpture_imgbtn_sculpture_return_imgReleased_data
})
sculpture_imgbtn_sculpture_return.set_src(lv.imgbtn.STATE.RELEASED, sculpture_imgbtn_sculpture_return_imgReleased, None, None)





sculpture_imgbtn_sculpture_return.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_sculpture_imgbtn_sculpture_return_main_main_default
style_sculpture_imgbtn_sculpture_return_main_main_default = lv.style_t()
style_sculpture_imgbtn_sculpture_return_main_main_default.init()
style_sculpture_imgbtn_sculpture_return_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_sculpture_imgbtn_sculpture_return_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_sculpture_imgbtn_sculpture_return_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sculpture_imgbtn_sculpture_return_main_main_default.set_text_font(lv.font_montserrat_16)
style_sculpture_imgbtn_sculpture_return_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sculpture_imgbtn_sculpture_return_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_sculpture_imgbtn_sculpture_return_main_main_default.set_img_recolor_opa(0)
style_sculpture_imgbtn_sculpture_return_main_main_default.set_img_opa(255)

# add style for sculpture_imgbtn_sculpture_return
sculpture_imgbtn_sculpture_return.add_style(style_sculpture_imgbtn_sculpture_return_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_sculpture_imgbtn_sculpture_return_main_main_pressed
style_sculpture_imgbtn_sculpture_return_main_main_pressed = lv.style_t()
style_sculpture_imgbtn_sculpture_return_main_main_pressed.init()
style_sculpture_imgbtn_sculpture_return_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_sculpture_imgbtn_sculpture_return_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_sculpture_imgbtn_sculpture_return_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sculpture_imgbtn_sculpture_return_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_sculpture_imgbtn_sculpture_return_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sculpture_imgbtn_sculpture_return_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_sculpture_imgbtn_sculpture_return_main_main_pressed.set_img_recolor_opa(0)
style_sculpture_imgbtn_sculpture_return_main_main_pressed.set_img_opa(255)

# add style for sculpture_imgbtn_sculpture_return
sculpture_imgbtn_sculpture_return.add_style(style_sculpture_imgbtn_sculpture_return_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_sculpture_imgbtn_sculpture_return_main_main_checked
style_sculpture_imgbtn_sculpture_return_main_main_checked = lv.style_t()
style_sculpture_imgbtn_sculpture_return_main_main_checked.init()
style_sculpture_imgbtn_sculpture_return_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_sculpture_imgbtn_sculpture_return_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_sculpture_imgbtn_sculpture_return_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_sculpture_imgbtn_sculpture_return_main_main_checked.set_text_font(lv.font_montserrat_16)
style_sculpture_imgbtn_sculpture_return_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_sculpture_imgbtn_sculpture_return_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_sculpture_imgbtn_sculpture_return_main_main_checked.set_img_recolor_opa(0)
style_sculpture_imgbtn_sculpture_return_main_main_checked.set_img_opa(255)

# add style for sculpture_imgbtn_sculpture_return
sculpture_imgbtn_sculpture_return.add_style(style_sculpture_imgbtn_sculpture_return_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

sculpture_animimg_1 = lv.animimg(sculpture)
sculpture_animimg_1.set_pos(int(385),int(11))
sculpture_animimg_1.set_size(50,50)
sculpture_animimg_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
sculpture_animimg_1_animimgs = [None]*1
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-328374156.png','rb') as f:
        sculpture_animimg_1_animimg_data_0 = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-328374156.png')
    sys.exit()

sculpture_animimg_1_animimgs[0] = lv.img_dsc_t({
  'data_size': len(sculpture_animimg_1_animimg_data_0),
  'header': {'always_zero': 0, 'w': 50, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': sculpture_animimg_1_animimg_data_0
})

sculpture_animimg_1.set_src(sculpture_animimg_1_animimgs, 1)
sculpture_animimg_1.set_duration(30 * 1)
sculpture_animimg_1.set_repeat_count(3000)
sculpture_animimg_1.start()
setting = lv.obj()
setting.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_setting_main_main_default
style_setting_main_main_default = lv.style_t()
style_setting_main_main_default.init()
style_setting_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_setting_main_main_default.set_bg_opa(255)

# add style for setting
setting.add_style(style_setting_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

setting_imgbtn_setting_home_return = lv.imgbtn(setting)
setting_imgbtn_setting_home_return.set_pos(int(20),int(17))
setting_imgbtn_setting_home_return.set_size(100,50)
setting_imgbtn_setting_home_return.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1235204120.png','rb') as f:
        setting_imgbtn_setting_home_return_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1235204120.png')
    sys.exit()

setting_imgbtn_setting_home_return_imgReleased = lv.img_dsc_t({
  'data_size': len(setting_imgbtn_setting_home_return_imgReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setting_imgbtn_setting_home_return_imgReleased_data
})
setting_imgbtn_setting_home_return.set_src(lv.imgbtn.STATE.RELEASED, setting_imgbtn_setting_home_return_imgReleased, None, None)





setting_imgbtn_setting_home_return.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_setting_imgbtn_setting_home_return_main_main_default
style_setting_imgbtn_setting_home_return_main_main_default = lv.style_t()
style_setting_imgbtn_setting_home_return_main_main_default.init()
style_setting_imgbtn_setting_home_return_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setting_imgbtn_setting_home_return_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_setting_home_return_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_setting_home_return_main_main_default.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_setting_home_return_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_setting_home_return_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setting_imgbtn_setting_home_return_main_main_default.set_img_recolor_opa(0)
style_setting_imgbtn_setting_home_return_main_main_default.set_img_opa(255)

# add style for setting_imgbtn_setting_home_return
setting_imgbtn_setting_home_return.add_style(style_setting_imgbtn_setting_home_return_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_setting_imgbtn_setting_home_return_main_main_pressed
style_setting_imgbtn_setting_home_return_main_main_pressed = lv.style_t()
style_setting_imgbtn_setting_home_return_main_main_pressed.init()
style_setting_imgbtn_setting_home_return_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_imgbtn_setting_home_return_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_setting_home_return_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_setting_home_return_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_setting_home_return_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_setting_home_return_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_imgbtn_setting_home_return_main_main_pressed.set_img_recolor_opa(0)
style_setting_imgbtn_setting_home_return_main_main_pressed.set_img_opa(255)

# add style for setting_imgbtn_setting_home_return
setting_imgbtn_setting_home_return.add_style(style_setting_imgbtn_setting_home_return_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_setting_imgbtn_setting_home_return_main_main_checked
style_setting_imgbtn_setting_home_return_main_main_checked = lv.style_t()
style_setting_imgbtn_setting_home_return_main_main_checked.init()
style_setting_imgbtn_setting_home_return_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_imgbtn_setting_home_return_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_setting_home_return_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_setting_home_return_main_main_checked.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_setting_home_return_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_setting_home_return_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_imgbtn_setting_home_return_main_main_checked.set_img_recolor_opa(0)
style_setting_imgbtn_setting_home_return_main_main_checked.set_img_opa(255)

# add style for setting_imgbtn_setting_home_return
setting_imgbtn_setting_home_return.add_style(style_setting_imgbtn_setting_home_return_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

setting_imgbtn_parameter = lv.imgbtn(setting)
setting_imgbtn_parameter.set_pos(int(75),int(84))
setting_imgbtn_parameter.set_size(220,60)
setting_imgbtn_parameter.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1723510681.png','rb') as f:
        setting_imgbtn_parameter_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1723510681.png')
    sys.exit()

setting_imgbtn_parameter_imgReleased = lv.img_dsc_t({
  'data_size': len(setting_imgbtn_parameter_imgReleased_data),
  'header': {'always_zero': 0, 'w': 220, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setting_imgbtn_parameter_imgReleased_data
})
setting_imgbtn_parameter.set_src(lv.imgbtn.STATE.RELEASED, setting_imgbtn_parameter_imgReleased, None, None)





setting_imgbtn_parameter.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_setting_imgbtn_parameter_main_main_default
style_setting_imgbtn_parameter_main_main_default = lv.style_t()
style_setting_imgbtn_parameter_main_main_default.init()
style_setting_imgbtn_parameter_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setting_imgbtn_parameter_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_parameter_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_parameter_main_main_default.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_parameter_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_parameter_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setting_imgbtn_parameter_main_main_default.set_img_recolor_opa(0)
style_setting_imgbtn_parameter_main_main_default.set_img_opa(255)

# add style for setting_imgbtn_parameter
setting_imgbtn_parameter.add_style(style_setting_imgbtn_parameter_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_setting_imgbtn_parameter_main_main_pressed
style_setting_imgbtn_parameter_main_main_pressed = lv.style_t()
style_setting_imgbtn_parameter_main_main_pressed.init()
style_setting_imgbtn_parameter_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_imgbtn_parameter_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_parameter_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_parameter_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_parameter_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_parameter_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_imgbtn_parameter_main_main_pressed.set_img_recolor_opa(0)
style_setting_imgbtn_parameter_main_main_pressed.set_img_opa(255)

# add style for setting_imgbtn_parameter
setting_imgbtn_parameter.add_style(style_setting_imgbtn_parameter_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_setting_imgbtn_parameter_main_main_checked
style_setting_imgbtn_parameter_main_main_checked = lv.style_t()
style_setting_imgbtn_parameter_main_main_checked.init()
style_setting_imgbtn_parameter_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_imgbtn_parameter_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_parameter_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_parameter_main_main_checked.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_parameter_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_parameter_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_imgbtn_parameter_main_main_checked.set_img_recolor_opa(0)
style_setting_imgbtn_parameter_main_main_checked.set_img_opa(255)

# add style for setting_imgbtn_parameter
setting_imgbtn_parameter.add_style(style_setting_imgbtn_parameter_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

setting_imgbtn_language = lv.imgbtn(setting)
setting_imgbtn_language.set_pos(int(75),int(157))
setting_imgbtn_language.set_size(220,60)
setting_imgbtn_language.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1428521678.png','rb') as f:
        setting_imgbtn_language_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1428521678.png')
    sys.exit()

setting_imgbtn_language_imgReleased = lv.img_dsc_t({
  'data_size': len(setting_imgbtn_language_imgReleased_data),
  'header': {'always_zero': 0, 'w': 220, 'h': 60, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setting_imgbtn_language_imgReleased_data
})
setting_imgbtn_language.set_src(lv.imgbtn.STATE.RELEASED, setting_imgbtn_language_imgReleased, None, None)





setting_imgbtn_language.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_setting_imgbtn_language_main_main_default
style_setting_imgbtn_language_main_main_default = lv.style_t()
style_setting_imgbtn_language_main_main_default.init()
style_setting_imgbtn_language_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setting_imgbtn_language_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_language_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_language_main_main_default.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_language_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_language_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setting_imgbtn_language_main_main_default.set_img_recolor_opa(0)
style_setting_imgbtn_language_main_main_default.set_img_opa(255)

# add style for setting_imgbtn_language
setting_imgbtn_language.add_style(style_setting_imgbtn_language_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_setting_imgbtn_language_main_main_pressed
style_setting_imgbtn_language_main_main_pressed = lv.style_t()
style_setting_imgbtn_language_main_main_pressed.init()
style_setting_imgbtn_language_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_imgbtn_language_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_language_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_language_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_language_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_language_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_imgbtn_language_main_main_pressed.set_img_recolor_opa(0)
style_setting_imgbtn_language_main_main_pressed.set_img_opa(255)

# add style for setting_imgbtn_language
setting_imgbtn_language.add_style(style_setting_imgbtn_language_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_setting_imgbtn_language_main_main_checked
style_setting_imgbtn_language_main_main_checked = lv.style_t()
style_setting_imgbtn_language_main_main_checked.init()
style_setting_imgbtn_language_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_imgbtn_language_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_imgbtn_language_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_imgbtn_language_main_main_checked.set_text_font(lv.font_montserrat_16)
style_setting_imgbtn_language_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_imgbtn_language_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_imgbtn_language_main_main_checked.set_img_recolor_opa(0)
style_setting_imgbtn_language_main_main_checked.set_img_opa(255)

# add style for setting_imgbtn_language
setting_imgbtn_language.add_style(style_setting_imgbtn_language_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

setting_language = lv.obj()
setting_language.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_setting_language_main_main_default
style_setting_language_main_main_default = lv.style_t()
style_setting_language_main_main_default.init()
style_setting_language_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_setting_language_main_main_default.set_bg_opa(255)

# add style for setting_language
setting_language.add_style(style_setting_language_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

setting_language_imgbtn_setting_language_return = lv.imgbtn(setting_language)
setting_language_imgbtn_setting_language_return.set_pos(int(15),int(11))
setting_language_imgbtn_setting_language_return.set_size(100,50)
setting_language_imgbtn_setting_language_return.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1235204120.png','rb') as f:
        setting_language_imgbtn_setting_language_return_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1235204120.png')
    sys.exit()

setting_language_imgbtn_setting_language_return_imgReleased = lv.img_dsc_t({
  'data_size': len(setting_language_imgbtn_setting_language_return_imgReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setting_language_imgbtn_setting_language_return_imgReleased_data
})
setting_language_imgbtn_setting_language_return.set_src(lv.imgbtn.STATE.RELEASED, setting_language_imgbtn_setting_language_return_imgReleased, None, None)





setting_language_imgbtn_setting_language_return.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_setting_language_imgbtn_setting_language_return_main_main_default
style_setting_language_imgbtn_setting_language_return_main_main_default = lv.style_t()
style_setting_language_imgbtn_setting_language_return_main_main_default.init()
style_setting_language_imgbtn_setting_language_return_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setting_language_imgbtn_setting_language_return_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_language_return_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_language_return_main_main_default.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_language_return_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_language_return_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setting_language_imgbtn_setting_language_return_main_main_default.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_language_return_main_main_default.set_img_opa(255)

# add style for setting_language_imgbtn_setting_language_return
setting_language_imgbtn_setting_language_return.add_style(style_setting_language_imgbtn_setting_language_return_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_setting_language_imgbtn_setting_language_return_main_main_pressed
style_setting_language_imgbtn_setting_language_return_main_main_pressed = lv.style_t()
style_setting_language_imgbtn_setting_language_return_main_main_pressed.init()
style_setting_language_imgbtn_setting_language_return_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_language_imgbtn_setting_language_return_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_language_return_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_language_return_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_language_return_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_language_return_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_language_imgbtn_setting_language_return_main_main_pressed.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_language_return_main_main_pressed.set_img_opa(255)

# add style for setting_language_imgbtn_setting_language_return
setting_language_imgbtn_setting_language_return.add_style(style_setting_language_imgbtn_setting_language_return_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_setting_language_imgbtn_setting_language_return_main_main_checked
style_setting_language_imgbtn_setting_language_return_main_main_checked = lv.style_t()
style_setting_language_imgbtn_setting_language_return_main_main_checked.init()
style_setting_language_imgbtn_setting_language_return_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_language_imgbtn_setting_language_return_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_language_return_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_language_return_main_main_checked.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_language_return_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_language_return_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_language_imgbtn_setting_language_return_main_main_checked.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_language_return_main_main_checked.set_img_opa(255)

# add style for setting_language_imgbtn_setting_language_return
setting_language_imgbtn_setting_language_return.add_style(style_setting_language_imgbtn_setting_language_return_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

setting_language_imgbtn_setting_chinese = lv.imgbtn(setting_language)
setting_language_imgbtn_setting_chinese.set_pos(int(77),int(81))
setting_language_imgbtn_setting_chinese.set_size(150,50)
setting_language_imgbtn_setting_chinese.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-912549422.png','rb') as f:
        setting_language_imgbtn_setting_chinese_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-912549422.png')
    sys.exit()

setting_language_imgbtn_setting_chinese_imgReleased = lv.img_dsc_t({
  'data_size': len(setting_language_imgbtn_setting_chinese_imgReleased_data),
  'header': {'always_zero': 0, 'w': 150, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setting_language_imgbtn_setting_chinese_imgReleased_data
})
setting_language_imgbtn_setting_chinese.set_src(lv.imgbtn.STATE.RELEASED, setting_language_imgbtn_setting_chinese_imgReleased, None, None)





setting_language_imgbtn_setting_chinese.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_setting_language_imgbtn_setting_chinese_main_main_default
style_setting_language_imgbtn_setting_chinese_main_main_default = lv.style_t()
style_setting_language_imgbtn_setting_chinese_main_main_default.init()
style_setting_language_imgbtn_setting_chinese_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setting_language_imgbtn_setting_chinese_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_chinese_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_chinese_main_main_default.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_chinese_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_chinese_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setting_language_imgbtn_setting_chinese_main_main_default.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_chinese_main_main_default.set_img_opa(255)

# add style for setting_language_imgbtn_setting_chinese
setting_language_imgbtn_setting_chinese.add_style(style_setting_language_imgbtn_setting_chinese_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_setting_language_imgbtn_setting_chinese_main_main_pressed
style_setting_language_imgbtn_setting_chinese_main_main_pressed = lv.style_t()
style_setting_language_imgbtn_setting_chinese_main_main_pressed.init()
style_setting_language_imgbtn_setting_chinese_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_language_imgbtn_setting_chinese_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_chinese_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_chinese_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_chinese_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_chinese_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_language_imgbtn_setting_chinese_main_main_pressed.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_chinese_main_main_pressed.set_img_opa(255)

# add style for setting_language_imgbtn_setting_chinese
setting_language_imgbtn_setting_chinese.add_style(style_setting_language_imgbtn_setting_chinese_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_setting_language_imgbtn_setting_chinese_main_main_checked
style_setting_language_imgbtn_setting_chinese_main_main_checked = lv.style_t()
style_setting_language_imgbtn_setting_chinese_main_main_checked.init()
style_setting_language_imgbtn_setting_chinese_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_language_imgbtn_setting_chinese_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_chinese_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_chinese_main_main_checked.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_chinese_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_chinese_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_language_imgbtn_setting_chinese_main_main_checked.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_chinese_main_main_checked.set_img_opa(255)

# add style for setting_language_imgbtn_setting_chinese
setting_language_imgbtn_setting_chinese.add_style(style_setting_language_imgbtn_setting_chinese_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

setting_language_imgbtn_setting_english = lv.imgbtn(setting_language)
setting_language_imgbtn_setting_english.set_pos(int(276),int(81))
setting_language_imgbtn_setting_english.set_size(150,50)
setting_language_imgbtn_setting_english.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-968899121.png','rb') as f:
        setting_language_imgbtn_setting_english_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-968899121.png')
    sys.exit()

setting_language_imgbtn_setting_english_imgReleased = lv.img_dsc_t({
  'data_size': len(setting_language_imgbtn_setting_english_imgReleased_data),
  'header': {'always_zero': 0, 'w': 150, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setting_language_imgbtn_setting_english_imgReleased_data
})
setting_language_imgbtn_setting_english.set_src(lv.imgbtn.STATE.RELEASED, setting_language_imgbtn_setting_english_imgReleased, None, None)





setting_language_imgbtn_setting_english.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_setting_language_imgbtn_setting_english_main_main_default
style_setting_language_imgbtn_setting_english_main_main_default = lv.style_t()
style_setting_language_imgbtn_setting_english_main_main_default.init()
style_setting_language_imgbtn_setting_english_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setting_language_imgbtn_setting_english_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_english_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_english_main_main_default.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_english_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_english_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setting_language_imgbtn_setting_english_main_main_default.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_english_main_main_default.set_img_opa(255)

# add style for setting_language_imgbtn_setting_english
setting_language_imgbtn_setting_english.add_style(style_setting_language_imgbtn_setting_english_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_setting_language_imgbtn_setting_english_main_main_pressed
style_setting_language_imgbtn_setting_english_main_main_pressed = lv.style_t()
style_setting_language_imgbtn_setting_english_main_main_pressed.init()
style_setting_language_imgbtn_setting_english_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_language_imgbtn_setting_english_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_english_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_english_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_english_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_english_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_language_imgbtn_setting_english_main_main_pressed.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_english_main_main_pressed.set_img_opa(255)

# add style for setting_language_imgbtn_setting_english
setting_language_imgbtn_setting_english.add_style(style_setting_language_imgbtn_setting_english_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_setting_language_imgbtn_setting_english_main_main_checked
style_setting_language_imgbtn_setting_english_main_main_checked = lv.style_t()
style_setting_language_imgbtn_setting_english_main_main_checked.init()
style_setting_language_imgbtn_setting_english_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_language_imgbtn_setting_english_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_language_imgbtn_setting_english_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_language_imgbtn_setting_english_main_main_checked.set_text_font(lv.font_montserrat_16)
style_setting_language_imgbtn_setting_english_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_language_imgbtn_setting_english_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_language_imgbtn_setting_english_main_main_checked.set_img_recolor_opa(0)
style_setting_language_imgbtn_setting_english_main_main_checked.set_img_opa(255)

# add style for setting_language_imgbtn_setting_english
setting_language_imgbtn_setting_english.add_style(style_setting_language_imgbtn_setting_english_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

setting_parameter = lv.obj()
setting_parameter.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_setting_parameter_main_main_default
style_setting_parameter_main_main_default = lv.style_t()
style_setting_parameter_main_main_default.init()
style_setting_parameter_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_setting_parameter_main_main_default.set_bg_opa(255)

# add style for setting_parameter
setting_parameter.add_style(style_setting_parameter_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

setting_parameter_imgbtn_setting_paremeter_return = lv.imgbtn(setting_parameter)
setting_parameter_imgbtn_setting_paremeter_return.set_pos(int(21),int(16))
setting_parameter_imgbtn_setting_paremeter_return.set_size(100,50)
setting_parameter_imgbtn_setting_paremeter_return.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1235204120.png','rb') as f:
        setting_parameter_imgbtn_setting_paremeter_return_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1235204120.png')
    sys.exit()

setting_parameter_imgbtn_setting_paremeter_return_imgReleased = lv.img_dsc_t({
  'data_size': len(setting_parameter_imgbtn_setting_paremeter_return_imgReleased_data),
  'header': {'always_zero': 0, 'w': 100, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setting_parameter_imgbtn_setting_paremeter_return_imgReleased_data
})
setting_parameter_imgbtn_setting_paremeter_return.set_src(lv.imgbtn.STATE.RELEASED, setting_parameter_imgbtn_setting_paremeter_return_imgReleased, None, None)





setting_parameter_imgbtn_setting_paremeter_return.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default = lv.style_t()
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.init()
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.set_text_font(lv.font_montserrat_16)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.set_img_recolor_opa(0)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default.set_img_opa(255)

# add style for setting_parameter_imgbtn_setting_paremeter_return
setting_parameter_imgbtn_setting_paremeter_return.add_style(style_setting_parameter_imgbtn_setting_paremeter_return_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed = lv.style_t()
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.init()
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.set_img_recolor_opa(0)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed.set_img_opa(255)

# add style for setting_parameter_imgbtn_setting_paremeter_return
setting_parameter_imgbtn_setting_paremeter_return.add_style(style_setting_parameter_imgbtn_setting_paremeter_return_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked = lv.style_t()
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.init()
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.set_text_font(lv.font_montserrat_16)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.set_img_recolor_opa(0)
style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked.set_img_opa(255)

# add style for setting_parameter_imgbtn_setting_paremeter_return
setting_parameter_imgbtn_setting_paremeter_return.add_style(style_setting_parameter_imgbtn_setting_paremeter_return_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

setting_parameter_imgbtn_setting = lv.imgbtn(setting_parameter)
setting_parameter_imgbtn_setting.set_pos(int(63),int(76))
setting_parameter_imgbtn_setting.set_size(189,50)
setting_parameter_imgbtn_setting.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1045974524.png','rb') as f:
        setting_parameter_imgbtn_setting_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1045974524.png')
    sys.exit()

setting_parameter_imgbtn_setting_imgReleased = lv.img_dsc_t({
  'data_size': len(setting_parameter_imgbtn_setting_imgReleased_data),
  'header': {'always_zero': 0, 'w': 189, 'h': 50, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': setting_parameter_imgbtn_setting_imgReleased_data
})
setting_parameter_imgbtn_setting.set_src(lv.imgbtn.STATE.RELEASED, setting_parameter_imgbtn_setting_imgReleased, None, None)





setting_parameter_imgbtn_setting.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_setting_parameter_imgbtn_setting_main_main_default
style_setting_parameter_imgbtn_setting_main_main_default = lv.style_t()
style_setting_parameter_imgbtn_setting_main_main_default.init()
style_setting_parameter_imgbtn_setting_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_setting_parameter_imgbtn_setting_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_parameter_imgbtn_setting_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_parameter_imgbtn_setting_main_main_default.set_text_font(lv.font_montserrat_16)
style_setting_parameter_imgbtn_setting_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_parameter_imgbtn_setting_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_setting_parameter_imgbtn_setting_main_main_default.set_img_recolor_opa(0)
style_setting_parameter_imgbtn_setting_main_main_default.set_img_opa(255)

# add style for setting_parameter_imgbtn_setting
setting_parameter_imgbtn_setting.add_style(style_setting_parameter_imgbtn_setting_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_setting_parameter_imgbtn_setting_main_main_pressed
style_setting_parameter_imgbtn_setting_main_main_pressed = lv.style_t()
style_setting_parameter_imgbtn_setting_main_main_pressed.init()
style_setting_parameter_imgbtn_setting_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_parameter_imgbtn_setting_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_parameter_imgbtn_setting_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_parameter_imgbtn_setting_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_setting_parameter_imgbtn_setting_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_parameter_imgbtn_setting_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_parameter_imgbtn_setting_main_main_pressed.set_img_recolor_opa(0)
style_setting_parameter_imgbtn_setting_main_main_pressed.set_img_opa(255)

# add style for setting_parameter_imgbtn_setting
setting_parameter_imgbtn_setting.add_style(style_setting_parameter_imgbtn_setting_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_setting_parameter_imgbtn_setting_main_main_checked
style_setting_parameter_imgbtn_setting_main_main_checked = lv.style_t()
style_setting_parameter_imgbtn_setting_main_main_checked.init()
style_setting_parameter_imgbtn_setting_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_setting_parameter_imgbtn_setting_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_setting_parameter_imgbtn_setting_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_setting_parameter_imgbtn_setting_main_main_checked.set_text_font(lv.font_montserrat_16)
style_setting_parameter_imgbtn_setting_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_setting_parameter_imgbtn_setting_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_setting_parameter_imgbtn_setting_main_main_checked.set_img_recolor_opa(0)
style_setting_parameter_imgbtn_setting_main_main_checked.set_img_opa(255)

# add style for setting_parameter_imgbtn_setting
setting_parameter_imgbtn_setting.add_style(style_setting_parameter_imgbtn_setting_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

about = lv.obj()
about.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_about_main_main_default
style_about_main_main_default = lv.style_t()
style_about_main_main_default.init()
style_about_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_about_main_main_default.set_bg_opa(255)

# add style for about
about.add_style(style_about_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_img_info = lv.img(about)
about_img_info.set_pos(int(91),int(72))
about_img_info.set_size(290,102)
about_img_info.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
about_img_info.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1244959785.png','rb') as f:
        about_img_info_img_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp1244959785.png')
    sys.exit()

about_img_info_img = lv.img_dsc_t({
  'data_size': len(about_img_info_img_data),
  'header': {'always_zero': 0, 'w': 290, 'h': 102, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': about_img_info_img_data
})

about_img_info.set_src(about_img_info_img)
about_img_info.set_pivot(0,0)
about_img_info.set_angle(0)
# create style style_about_img_info_main_main_default
style_about_img_info_main_main_default = lv.style_t()
style_about_img_info_main_main_default.init()
style_about_img_info_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_about_img_info_main_main_default.set_img_recolor_opa(0)
style_about_img_info_main_main_default.set_img_opa(255)

# add style for about_img_info
about_img_info.add_style(style_about_img_info_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

about_imgbtn_about_return = lv.imgbtn(about)
about_imgbtn_about_return.set_pos(int(26),int(15))
about_imgbtn_about_return.set_size(102,38)
about_imgbtn_about_return.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-518019228.png','rb') as f:
        about_imgbtn_about_return_imgReleased_data = f.read()
except:
    print('Could not open D:\\LVGL\\LarseBox\\generated\\mPythonImages\\mp-518019228.png')
    sys.exit()

about_imgbtn_about_return_imgReleased = lv.img_dsc_t({
  'data_size': len(about_imgbtn_about_return_imgReleased_data),
  'header': {'always_zero': 0, 'w': 102, 'h': 38, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': about_imgbtn_about_return_imgReleased_data
})
about_imgbtn_about_return.set_src(lv.imgbtn.STATE.RELEASED, about_imgbtn_about_return_imgReleased, None, None)





about_imgbtn_about_return.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_about_imgbtn_about_return_main_main_default
style_about_imgbtn_about_return_main_main_default = lv.style_t()
style_about_imgbtn_about_return_main_main_default.init()
style_about_imgbtn_about_return_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_about_imgbtn_about_return_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_about_imgbtn_about_return_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_about_imgbtn_about_return_main_main_default.set_text_font(lv.font_montserrat_16)
style_about_imgbtn_about_return_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_about_imgbtn_about_return_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_about_imgbtn_about_return_main_main_default.set_img_recolor_opa(0)
style_about_imgbtn_about_return_main_main_default.set_img_opa(255)

# add style for about_imgbtn_about_return
about_imgbtn_about_return.add_style(style_about_imgbtn_about_return_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_about_imgbtn_about_return_main_main_pressed
style_about_imgbtn_about_return_main_main_pressed = lv.style_t()
style_about_imgbtn_about_return_main_main_pressed.init()
style_about_imgbtn_about_return_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_about_imgbtn_about_return_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_about_imgbtn_about_return_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_about_imgbtn_about_return_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_about_imgbtn_about_return_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_about_imgbtn_about_return_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_about_imgbtn_about_return_main_main_pressed.set_img_recolor_opa(0)
style_about_imgbtn_about_return_main_main_pressed.set_img_opa(255)

# add style for about_imgbtn_about_return
about_imgbtn_about_return.add_style(style_about_imgbtn_about_return_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_about_imgbtn_about_return_main_main_checked
style_about_imgbtn_about_return_main_main_checked = lv.style_t()
style_about_imgbtn_about_return_main_main_checked.init()
style_about_imgbtn_about_return_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_about_imgbtn_about_return_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_about_imgbtn_about_return_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_about_imgbtn_about_return_main_main_checked.set_text_font(lv.font_montserrat_16)
style_about_imgbtn_about_return_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_about_imgbtn_about_return_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_about_imgbtn_about_return_main_main_checked.set_img_recolor_opa(0)
style_about_imgbtn_about_return_main_main_checked.set_img_opa(255)

# add style for about_imgbtn_about_return
about_imgbtn_about_return.add_style(style_about_imgbtn_about_return_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)















# content from custom.py

# Load the default screen
lv.scr_load(home)

while SDL.check():
    time.sleep_ms(5)
