# CRKBD Digimon OLED
![CRKBD Digimon OLED](https://user-images.githubusercontent.com/45733259/83145414-b460d080-a12f-11ea-8854-76afb7bb1e1e.png)

Breding Digimon with the your Corne Keyboard (CRKBD).

## Usage
Replace `qmk_firmware/keyboards/crkbd/` with this repository file.

## Flash Your Keyboard
```bash
$ make crkbd:default:avrdude
```

## Change the Digimon to be bred
Change `keymaps/default/config.h`, the digimon to be bred will be changed.

Guilmon
```c:keymaps/default/config.h
#define IS_MASTER 1
```

Gabumon
```c:keymaps/default/config.h
#define IS_MASTER 0
```

## Other keyboards with OLED
I think it's possible to breed Digimon by customizing the source code on other keyboards with OLED that work with [QMK](https://github.com/qmk/qmk_firmware).