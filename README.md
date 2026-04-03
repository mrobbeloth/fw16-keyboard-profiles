# Framework Laptop 16 Keyboard Profiles

Manage keyboard and RGB macropad profiles for the Framework Laptop 16,
configured via [keyboard.frame.work](https://keyboard.frame.work/).

## Macropad Macro Key Positions (Layer 0)

The RGB Macropad has 4 macro keys on Layer 0:

| Key Index | Keycode   | Physical Position        |
|-----------|-----------|--------------------------|
| 17        | MACRO(0)  | Top area, left of pair   |
| 18        | MACRO(1)  | Top area, right of pair  |
| 20        | MACRO(3)  | Middle area              |
| 28        | MACRO(2)  | Lower area               |

All other Layer 0 keys remain standard numpad (numbers, operators, enter).

## Profiles

### vscode-general — Everyday VS Code

| Macro | Action                    | VIA Macro String                                        |
|-------|---------------------------|---------------------------------------------------------|
| 0     | Format Doc + Save All     | `{KC_LCTL,KC_K},{KC_LCTL,KC_D},{KC_LCTL,KC_K},{KC_S}`  |
| 1     | Command Palette           | `{KC_LCTL,KC_LSFT,KC_P}`                               |
| 2     | Hide Panel + Sidebar      | `{KC_LCTL,KC_J},{KC_LCTL,KC_B}`                        |
| 3     | Toggle Zen Mode           | `{KC_LCTL,KC_K},{KC_Z}`                                |

### vscode-debug — Debugging Sessions

| Macro | Action                    | VIA Macro String                  |
|-------|---------------------------|-----------------------------------|
| 0     | Start / Continue          | `{KC_F5}`                         |
| 1     | Step Over                 | `{KC_F10}`                        |
| 2     | Step Into                 | `{KC_F11}`                        |
| 3     | Restart Debug             | `{KC_LCTL,KC_LSFT,KC_F5}`        |

### vscode-refactor — Code Editing

| Macro | Action                    | VIA Macro String                  |
|-------|---------------------------|-----------------------------------|
| 0     | Rename Symbol             | `{KC_F2}`                         |
| 1     | Quick Fix / Code Actions  | `{KC_LCTL,KC_DOT}`               |
| 2     | Format Document           | `{KC_LCTL,KC_LSFT,KC_I}`         |
| 3     | Select Line + Cut         | `{KC_LCTL,KC_L},{KC_LCTL,KC_X}`  |

### vscode-navigation — File & Symbol Navigation

| Macro | Action                    | VIA Macro String                      |
|-------|---------------------------|---------------------------------------|
| 0     | Split Right + Quick Open  | `{KC_LCTL,KC_BSLS},{KC_LCTL,KC_P}`   |
| 1     | Go to Symbol in Workspace | `{KC_LCTL,KC_T}`                      |
| 2     | Find in Files             | `{KC_LCTL,KC_LSFT,KC_F}`             |
| 3     | Duplicate Line Down       | `{KC_LSFT,KC_LALT,KC_DOWN}`          |

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

## Project Structure

```
fw16-keyboard-profiles/
├── baseline/                  # Original exported layouts (do not edit)
│   ├── framework_laptop_16_keyboard___ansi.layout.json
│   └── framework_laptop_16_rgb_macropad.layout.json
├── profiles/
│   ├── keyboard/              # Keyboard profiles
│   │   └── framework_laptop_16_keyboard___ansi.layout.json
│   └── macropad/              # Macropad profiles
│       ├── vscode-general/
│       ├── vscode-debug/
│       ├── vscode-refactor/
│       └── vscode-navigation/
├── scripts/
│   └── swap-profile.sh        # Profile switcher
└── README.md
```

## Adding a New Profile

1. Copy an existing profile directory under `profiles/macropad/`
2. Edit the `macros` array in the JSON (indices 0–15 map to MACRO(0)–MACRO(15))
3. Update this README with the new profile's macro table

## References

- [VIA Configurator](https://keyboard.frame.work/)
- [VIA Specification](https://caniusevia.com/docs/specification)
- [VIA App Source](https://github.com/the-via/app)
- [VIA Macro Syntax](https://github.com/saikocat/keebs/blob/master/docs/pratical_via_keymap_guide.md#macros)
  - `{KC_X,KC_Y}` — chord (simultaneous keys)
  - `{KC_X},{KC_Y}` — sequence (one after another)
