# CRKBD Digimon OLED

Breed and raise Digimon with a Corne (CRKBD) keyboard using QMK and a custom SSD1306 OLED renderer.

## Project layout and QMK compatibility

This repository contains the Digimon keymap, sprite data, and custom OLED/I²C implementation for the Corne keyboard. The official QMK repository is the source of truth for Corne keyboard metadata and the split-keyboard implementation.

- **QMK version used by CI:** `0.34.7`
- **Keyboard target:** `crkbd/rev1`
- **Keymap:** `default`
- **Keyboard metadata:** upstream `keyboards/crkbd/rev1/keyboard.json`

The old, duplicated Corne implementation files previously stored in this repository (including the legacy `rev1/` split-communication code) have been removed. The CI workflow overlays this repository's custom files onto a clean QMK checkout without replacing upstream keyboard files.

## Build locally

1. Check out QMK Firmware and install its build dependencies following the [QMK setup guide](https://docs.qmk.fm/newbs_getting_started).
2. Use QMK Firmware version `0.34.7`.
3. Place this repository's files into `keyboards/crkbd/` in the QMK checkout, preserving the upstream Corne files.
4. From the QMK checkout, validate the metadata and compile:

   ```sh
   qmk info -kb crkbd/rev1
   qmk compile -kb crkbd/rev1 -km default
   ```

The GitHub Actions workflow performs the overlay, metadata validation, build, and memory-budget checks automatically.

## Download the CI firmware

Open the [GitHub Actions runs](https://github.com/ukeloop/crkbd-digimon-oled/actions), select a successful **Build firmware** run, and download the `crkbd-digimon-oled-firmware` artifact.

The artifact is a build output, not a guarantee that the firmware is compatible with every Corne controller or revision. Confirm your keyboard's MCU and hardware revision before flashing.

## Flash the firmware

With QMK CLI installed, connect the keyboard and run this from the QMK checkout:

```sh
qmk flash -kb crkbd/rev1 -km default
```

Follow the reset/bootloader procedure for your controller when prompted. If your Corne uses an ATmega32U4, verify that the firmware was built for the correct Corne revision and bootloader. Never flash firmware built for a different MCU or keyboard revision.

For split keyboards, flash each half as required by the controller and bootloader workflow described in the [QMK flashing guide](https://docs.qmk.fm/flashing).

## Choose the Digimon

Edit `keymaps/default/config.h`:

- Guilmon: `#define IS_MASTER 1`
- Gabumon: `#define IS_MASTER 0`

Rebuild the firmware after changing this setting.

## Implementation notes

- Sprite data is stored in program memory with `PROGMEM` to reduce SRAM use on the ATmega32U4.
- The custom OLED renderer uses a shared framebuffer and throttled, dirty-screen updates.
- The I²C implementation uses bounded waits to detect communication errors instead of waiting indefinitely.
- OLED rendering, split communication, and hardware behavior still need to be verified on the physical keyboard after flashing.
