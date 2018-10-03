DZ60 flashing instruction: 

Hold spacebar + b and plug the usb plug in to enter bootloader mode

Erase the flash (If force is not used, sometimes we get write error

```
dfu-programmer atmega32u4 erase --force
```

Flash the firmware

```
dfu-programmer atmega32u4 flash qmk60.hex --debug 2
```

Reset the board and voila!

```
dfu-programmer atmega32u4 reset
```


Note: we are using the exported hex from http://qmkeyboard.cn/ and the json files include the settings for the site. Unfortunately we are having some issue with compiling our own firmware so that is problem for another day! This means that some of the functions/macros we had in TADA68 is not included but heh, it's still an awesome keyboard!
