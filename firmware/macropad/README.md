# Custom QMK Firmware for Framework 16 RGB Macropad

Layer-aware RGB lighting with OSU Scarlet & Gray theme.

## What It Does

- Layer 0 (Numpad): Your normal RGB animation (set via VIA or Fn layer controls).
  Set this to scarlet (#BB0000) for the OSU theme.
- Layer 2 (VS Code Macros): Automatically switches to a gray (#666666) breathing
  animation so you instantly know you're on the macro layer.
- Releasing NumLock restores your previous RGB mode and color.

The `_noeeprom` variants are used so the layer switch doesn't permanently
overwrite your saved RGB settings.

## Changes from Stock Firmware

1. `LT(2, KC_NUM)` on the NumLock key — tap for NumLock, hold for Layer 2
2. `layer_state_set_user()` callback — switches RGB on layer change
3. Layer 2 (`_FACTORY`) is repurposed as the VS Code macro layer
   (the actual macro strings are configured via VIA, not in firmware)

## Build Instructions

### Prerequisites

```bash
# Clone the Framework QMK fork
git clone git@github.com:FrameworkComputer/qmk_firmware.git
cd qmk_firmware
git checkout v0.2.9
git submodule update --init --recursive
```

### Install the Custom Keymap

```bash
# Create a custom keymap directory
mkdir -p keyboards/framework/macropad/keymaps/osu

# Copy this keymap.c into it
cp /path/to/fw16-keyboard-profiles/firmware/macropad/keymap.c \
   keyboards/framework/macropad/keymaps/osu/keymap.c
```

### Build

```bash
# Using Docker/Podman
RUNTIME="podman" util/docker_build.sh framework/macropad:osu:build

# Or with qmk CLI
qmk compile -kb framework/macropad -km osu
```

This produces `framework_macropad_osu.uf2`.

### Flash

1. Remove the macropad from the laptop
2. Hold the `2` and `6` keys on the macropad
3. Re-insert the macropad (keep holding)
4. Install the trackpad module
5. Wait for the mass storage device to mount
6. Release the keys
7. Copy the `.uf2` file to the mounted drive

The macropad will reboot with the new firmware.

### Reverting to Stock

Download the stock firmware from the
[Framework QMK releases page](https://github.com/FrameworkComputer/qmk_firmware/releases)
and flash it using the same process above.

## Setting the OSU Scarlet Base Color

After flashing, use the Fn layer (toggle NumLock off) to set the base color:

1. Press `RGB_HUI` / `RGB_HUD` to set Hue to 0 (red)
2. Press `RGB_SAI` to max saturation
3. Pick your preferred animation mode with `RGB_MOD`

This becomes your Layer 0 look. Layer 2 will automatically override to
gray breathing when active.
