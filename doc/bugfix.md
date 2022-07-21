# ESP32_LaserBox_E

## 2022-07-21

1、修改PWM输出初始化 加入ledc_bind_channel_timer() 这个函数

2、修改截断精度lroundf() / truncf()

3、修改_handle_web_command()，优化http协议解析

