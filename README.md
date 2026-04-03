# Framework Laptop 16 Keyboard Profiles

Manage keyboard and RGB macropad profiles for the Framework Laptop 16,
configured via [keyboard.frame.work](https://keyboard.frame.work/).

## Macropad Physical Layout

```
Layer 0 (Default - Numpad)        Layer 2 (VS Code Macro Grid)
┌──────┬──────┬──────┬──────┐     ┌──────┬──────┬──────┬──────┐
│NumLk │  /   │  *   │  -   │     │ M(4) │ M(8) │M(13) │M(14) │
│ [0]  │ [4]  │ [9]  │ [14] │     │MvEdL │MvEdR │CpLnDn│DelLn │
├──────┼──────┼──────┼──────┤     ├──────┼──────┼──────┼──────┤
│  7   │  8   │  9   │      │     │ M(5) │ M(9) │M(10) │      │
│ [1]  │ [5]  │ [10] │  +   │     │GoSym │GoSymW│FindFl│  +   │
├──────┼──────┼──────┤ [15] │     ├──────┼──────┼──────┤(pass)│
│  4   │  5   │  6   │ [21] │     │ M(6) │M(10) │M(15) │      │
│ [2]  │ [6]  │ [11] │      │     │NxtMch│SelAll│ Term │      │
├──────┼──────┼──────┼──────┤     ├──────┼──────┼──────┼──────┤
│  1   │  2   │  3   │      │     │ M(7) │M(11) │  3   │      │
│ [3]  │ [7]  │ [12] │Enter │     │CmdPal│SelAll│(pass)│Enter │
├──────┼──────┤      │ [16] │     ├──────┼──────┤      │(pass)│
│ M(0) │ M(1) │  .   │ [22] │     │ M(0) │ M(1) │  .   │      │
│ [17] │ [18] │ [13] │      │     │(same)│(same)│(pass)│      │
├──────┴──┬───┤      ├──────┤     ├──────┴──┬───┤      ├──────┤
│  0      │M(3)│ M(2)│             │ M(12)  │M(3)│ M(2) │
│ [8][23] │[20]│ [28]│             │Comment │same│(same) │
└─────────┴────┴─────┘             └────────┴────┴───────┘
```

Keys marked `(pass)` use `KC_TRNS` — they fall through to Layer 0 so you
keep `+`, `Enter`, `.`, and `3` available even on Layer 2.

## Layer 2 Macro Grid (Shared Across All Profiles)

| Slot | Position | Action                        | VIA Macro String                          |
|------|----------|-------------------------------|-------------------------------------------|
| M(4) | NumLk    | Move Editor to Left Group     | `{KC_LCTL,KC_K},{KC_LCTL,KC_LEFT}`        |
| M(5) | 7        | Go to Symbol in File          | `{KC_LCTL,KC_LSFT,KC_O}`                 |
| M(6) | 4        | Add Next Match to Selection   | `{KC_LCTL,KC_D}`                          |
| M(7) | 1        | Command Palette               | `{KC_LCTL,KC_LSFT,KC_P}`                 |
| M(8) | /        | Move Editor to Right Group    | `{KC_LCTL,KC_K},{KC_LCTL,KC_RGHT}`       |
| M(9) | 8        | Go to Symbol in Workspace     | `{KC_LCTL,KC_T}`                          |
| M(10)| 5 / 9    | Find in Files                 | `{KC_LCTL,KC_LSFT,KC_F}`                 |
| M(11)| 2        | Select All Occurrences        | `{KC_LCTL,KC_LSFT,KC_L}`                 |
| M(12)| 0        | Comment Selection             | `{KC_LCTL,KC_K},{KC_LCTL,KC_C}`          |
| M(13)| *        | Copy Line Down (Multi-cursor) | `{KC_LCTL,KC_LSFT,KC_LALT,KC_DOWN}`      |
| M(14)| 9        | Delete Line                   | `{KC_LCTL,KC_LSFT,KC_K}`                 |
| M(15)| 6        | Toggle Terminal               | `` {KC_LCTL,KC_GRV} ``                   |

## Layer 0 Macro Keys (Profile-Specific)

### vscode-general — Everyday VS Code

| Macro | Action                    | VIA Macro String                                        |
|-------|---------------------------|---------------------------------------------------------|
| M(0)  | Format Doc + Save All     | `{KC_LCTL,KC_K},{KC_LCTL,KC_D},{KC_LCTL,KC_K},{KC_S}`  |
| M(1)  | Command Palette           | `{KC_LCTL,KC_LSFT,KC_P}`                               |
| M(2)  | Hide Panel + Sidebar      | `{KC_LCTL,KC_J},{KC_LCTL,KC_B}`                        |
| M(3)  | Toggle Zen Mode           | `{KC_LCTL,KC_K},{KC_Z}`                                |

### vscode-debug — Debugging Sessions

| Macro | Action                    | VIA Macro String                  |
|-------|---------------------------|-----------------------------------|
| M(0)  | Start / Continue          | `{KC_F5}`                         |
| M(1)  | Step Over                 | `{KC_F10}`                        |
| M(2)  | Step Into                 | `{KC_F11}`                        |
| M(3)  | Restart Debug             | `{KC_LCTL,KC_LSFT,KC_F5}`        |

### vscode-refactor — Code Editing

| Macro | Action                    | VIA Macro String                  |
|-------|---------------------------|-----------------------------------|
| M(0)  | Rename Symbol             | `{KC_F2}`                         |
| M(1)  | Quick Fix / Code Actions  | `{KC_LCTL,KC_DOT}`               |
| M(2)  | Format Document           | `{KC_LCTL,KC_LSFT,KC_I}`         |
| M(3)  | Select Line + Cut         | `{KC_LCTL,KC_L},{KC_LCTL,KC_X}`  |

### vscode-navigation — File & Symbol Navigation

| Macro | Action                    | VIA Macro String                      |
|-------|---------------------------|---------------------------------------|
| M(0)  | Split Right + Quick Open  | `{KC_LCTL,KC_BSLS},{KC_LCTL,KC_P}`   |
| M(1)  | Go to Symbol in Workspace | `{KC_LCTL,KC_T}`                      |
| M(2)  | Find in Files             | `{KC_LCTL,KC_LSFT,KC_F}`             |
| M(3)  | Duplicate Line Down       | `{KC_LSFT,KC_LALT,KC_DOWN}`          |

## Usage

### Swap the active macropad profile

```bash
./scripts/swap-profile.sh vscode-general
./scripts/swap-profile.sh vscode-debug
```

This copies the selected profile JSON to `~/Documents/` where you can
import it via the [Framework Keyboard Configurator](https://keyboard.frame.work/).

### List available profiles

```bash
./scripts/swap-profile.sh
```

## Accessing Layer 2

You need a key mapped to activate Layer 2. Options:

1. **Use the existing layer switching** — check if your macropad firmware
   already has a layer key (e.g., Fn or a `MO(2)` key).
2. **Remap a key** — e.g., change `KC_NLCK` (NumLock) on Layer 0 to
   `MO(2)` so holding NumLock activates the macro layer.
3. **Use `LT(2, KC_NLCK)`** — NumLock on tap, Layer 2 on hold.

## Project Structure

```
fw16-keyboard-profiles/
├── baseline/                  # Original exported layouts (do not edit)
│   ├── framework_laptop_16_keyboard___ansi.layout.json
│   └── framework_laptop_16_rgb_macropad.layout.json
├── profiles/
│   ├── keyboard/              # Keyboard profiles
│   └── macropad/              # Macropad profiles
│       ├── vscode-general/
│       ├── vscode-debug/
│       ├── vscode-refactor/
│       └── vscode-navigation/
├── scripts/
│   └── swap-profile.sh
└── README.md
```

## Adding a New Profile

1. Copy an existing profile directory under `profiles/macropad/`
2. Edit the `macros` array (indices 0–3 for profile-specific, 4–15 shared)
3. Update this README with the new profile's macro table

## References

- [VIA Configurator](https://keyboard.frame.work/)
- [VIA Specification](https://caniusevia.com/docs/specification)
- [VIA App Source](https://github.com/the-via/app)
- [VIA Macro Syntax](https://github.com/saikocat/keebs/blob/master/docs/pratical_via_keymap_guide.md#macros)
  - `{KC_X,KC_Y}` — chord (simultaneous keys)
  - `{KC_X},{KC_Y}` — sequence (one after another)
