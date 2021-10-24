# QMK Firmware Linked

This repo seperates the offical qmk_firmware repo from my customizations to it by synlinking in new files (existing files cannot be modified).

## Prerequisites

* QMK CLI (`python3 -m pip install qmk`) installed and setup
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
