# QMK Firmware Linked

This repo seperates the offical qmk_firmware repo from my customizations to it by synlinking in new files (existing files cannot be modified).

## Prerequisites

* QMK CLI (`python3 -m pip install qmk`) installed and setup (`qmk doctor`)
* stow (`sudo apt install stow`)

## Repo Setup 

```bash
# Init
git submodule add https://github.com/qmk/qmk_firmware.git

# Update
git submodule update --init --recursive

# Setup qmk home
# May require manual configuration in qmk.ini
qmk config user.qmk_home=$(pwd)/qmk_firmware
qmk config user.keyboard=splitkb/kyria
qmk config user.keymap=buckwich
```

## Usage

* Update qmk_firmware
```
git submodule update --init --recursive
```
* Link files (You can then use qmk as you normally would)
``` 
stow --target=qmk_firmware linked
```
* Unlink files
```
stow --delete --target=qmk_firmware linked 
```
* c to json
```
qmk c2json linked/keyboards/splitkb/kyria/keymaps/buckwich/keymap.c -km buckwich -kb splitkb/kyria -o buckwich.json
```
* json to custom c
``` 
node ../keyboard-converter/dist/bin/index.js \
--kbf ./linked/keyboards/splitkb/kyria/keymaps/buckwich/info.matrix.json \
--kmf ./linked/keyboards/splitkb/kyria/keymaps/buckwich/buckwich.json \
--qct ./linked/keyboards/splitkb/kyria/keymaps/buckwich/keymap.template.c \
--o ./linked/keyboards/splitkb/kyria/keymaps/buckwich/keymap.c
``` 