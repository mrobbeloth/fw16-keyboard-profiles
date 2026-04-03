#!/usr/bin/env bash
# Swap the active macropad profile by copying it to the Documents directory
# where it can be imported via https://keyboard.frame.work/
#
# Usage: ./swap-profile.sh <profile-name>
# Example: ./swap-profile.sh vscode-debug

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_DIR="$(dirname "$SCRIPT_DIR")"
DEST_DIR="$(dirname "$(dirname "$PROJECT_DIR")")"
MACROPAD_FILE="framework_laptop_16_rgb_macropad.layout.json"

PROFILES_DIR="$PROJECT_DIR/profiles/macropad"
AVAILABLE=$(ls -1 "$PROFILES_DIR")

if [ $# -lt 1 ]; then
  echo "Usage: $0 <profile-name>"
  echo ""
  echo "Available profiles:"
  echo "$AVAILABLE"
  exit 1
fi

PROFILE="$1"
SRC="$PROFILES_DIR/$PROFILE/$MACROPAD_FILE"

if [ ! -f "$SRC" ]; then
  echo "Error: Profile '$PROFILE' not found."
  echo ""
  echo "Available profiles:"
  echo "$AVAILABLE"
  exit 1
fi

cp "$SRC" "$DEST_DIR/$MACROPAD_FILE"
echo "Activated profile: $PROFILE"
echo "File copied to: $DEST_DIR/$MACROPAD_FILE"
echo ""
echo "Next: Import this file at https://keyboard.frame.work/"
