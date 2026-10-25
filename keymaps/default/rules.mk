
# If you want to change the display of OLED, you need to change here
# Legacy SSD1306 renderer and AVR TWI transport; keep upstream Corne matrix/split code.
SRC +=  ../../ssd1306.c \
        ../../i2c.c \
        ./lib/screen.c \
        ./lib/digimon/print_digimon.c \
        ./lib/digimon/digimon.c \
        ./lib/string/print_chara.c \
        ./lib/string/layer_state_reader.c \
        ./lib/string/keyloger.c \
        ./lib/string/wpm.c \
