
// This is the command sequence that initialises the ST7796 driver
//
// This setup information uses simple 8 bit SPI writecommand() and writedata() functions
//
// See ST7735_Setup.h file for an alternative format

#define TFT_INIT_DELAY 0
{
	delay(120);
    
    writecommand(0x11);
    delay(20);

	writecommand(0x36);

    writecommand(0xF0);
    writedata(0xC3);
    writecommand(0xF0);
    writedata(0x96);

    writecommand(0x36);
    // writedata(0xE8);
    writedata(0x28);
    writedata(0x28);

    writecommand(0x3A);

    writedata(0x55);
    writecommand(0xB4);
    writedata(0x01);
    writecommand(0xB7);
    writedata(0xC6);
    writecommand(0xE8);
    writedata(0x40);
    writedata(0x8A);
    writedata(0x00);
    writedata(0x00);
    writedata(0x29);
    writedata(0x19);
    writedata(0xA5);
    writedata(0x33);
    writecommand(0xC1);
    writedata(0x06);
    writecommand(0xC2);
    writedata(0xA7);
    writecommand(0xC5);
    writedata(0x18);
    writecommand(0xE0);         // Positive Voltage Gamma Control
    writedata(0xF0);
    writedata(0x09);
    writedata(0x0B);
    writedata(0x06);
    writedata(0x04);
    writedata(0x15);
    writedata(0x2F);
    writedata(0x54);
    writedata(0x42);
    writedata(0x3C);
    writedata(0x17);
    writedata(0x14);
    writedata(0x18);
    writedata(0x1B);
    writecommand(0xE1);         // Negative Voltage Gamma Control
    writedata(0xF0);
    writedata(0x09);
    writedata(0x0B);
    writedata(0x06);
    writedata(0x04);
    writedata(0x03);
    writedata(0x2D);
    writedata(0x43);
    writedata(0x42);
    writedata(0x3B);
    writedata(0x16);
    writedata(0x14);
    writedata(0x17);
    writedata(0x1B);
    writecommand(0xF0);
    writedata(0x3C);
    writecommand(0xF0);
    writedata(0x69);
    delay(120);                 // Delay 120ms
    writecommand(0x29);         // Display ON
}