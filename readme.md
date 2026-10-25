# CRKBD Digimon OLED

Breding Digimon with the Corne (CRKBD) keyboard using QMK and a custom SSD1306 OLED renderer.

## QMK compatibility and keyboard metadata

This repository adds the Digimon keymap, sprites, and custom OLED/I²C implementation to the upstream Corne keyboard. It intentionally uses the upstream Corne revision metadata rather than maintaining a divergent copy.

- QMK firmware version: `0.34.7`
- Keyboard target: `crkbd/rev1`
- Metadata source: `qmk_firmware/keyboards/crkbd/rev1/keyboard.json`

The legacy root-level `info.json` has been removed because it described an older, different layout and was not used by the build. CI validates that QMK can load the current `keyboard.json` before compiling.

## Build

From a QMK firmware checkout with this repository overlaid into `keyboards/crkbd/`:

```sh
qmk info -kb crkbd/rev1
qmk compile -kb crkbd/rev1 -km default
```

The CI workflow performs the overlay and build automatically. Download the `crkbd-digimon-oled-firmware` artifact from the successful [GitHub Actions run](https://github.com/ukeloop/crkbd-digimon-oled/actions).

## Flash

After confirming that the firmware matches your Corne revision and MCU, connect the keyboard and use:

```sh
qmk flash -kb crkbd/rev1 -km default
```

Follow the reset/bootloader instructions for your controller. Do not flash a firmware built for a different Corne revision or MCU.

## Select the Digimon

Edit `keymaps/default/config.h`:

- Guilmon: `#define IS_MASTER 1`
- Gabumon: `#define IS_MASTER 0`

## Notes

The current CI build targets an ATmega32U4-based Corne rev1. OLED animation, split communication, and physical hardware behavior still need final verification on the actual keyboard.
