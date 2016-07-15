# TMK Generic

* I'm not sure what the Magic + H does.
 Is this a menu that will pop up regardless of what platform and program is open? 

 Yes, this is sort of debugging.
 Use PJRC's [hid_listen](https://www.pjrc.com/teensy/hid_listen.html) to see debug messages.

# TMK/Ergodox specific

* I would like to configure my leds to indicate the active layer.
 I read that can be done, but I haven't seen an example for this firmware.
 Can someone please post an example or a link?

 TMK for Ergodox have support for seven (!) led's:
 - three on right
 - three on left (see http://geekhack.org/index.php?topic=22780.msg873819#msg873819 for more details)
 - Teensy onboard led as well

 Any of these leds can be used as layer indicator or NumLock/CapsLock/ScrollLock led.

 [Here is example](https://github.com/cub-uanic/tmk_keyboard/blob/cub_layout/keyboard/ergodox/matrix.c#L121-167)
 how you can assign some meaning to each led.
 In this code only left leds are used to show layers, but you can
 [change `led_set()`](https://github.com/cub-uanic/tmk_keyboard/blob/cub_layout/keyboard/ergodox/led.c)
 and do anything you want with all leds.

# Firmware

#### Where to get binaries?
https://github.com/cub-uanic/tmk_keyboard/releases

#### Where to get sources?
https://github.com/cub-uanic/tmk_keyboard/tree/master

#### How to compile?

    cd tmk_keyboard/keyboard/ergodox

    # just to be safe
    make -f Makefile.lufa clean

    # use one of these
    make -f Makefile.lufa #defaults to blazak
    make -f Makefile.lufa KEYMAP=dvorak
    make -f Makefile.lufa KEYMAP=colemak
    make -f Makefile.lufa KEYMAP=workman
    make -f Makefile.lufa KEYMAP=micro
    make -f Makefile.lufa KEYMAP=cub


# Layouts

## Filename

The filename should be of the form `keymap_name.c'
where `name' can be any text.
Then, the build system should use your keymapfile when you use

    make -f Makefile.lufa KEYMAP=name

from above.

## Writing

First, it is best to get familar with one of the working examples above.
If your lanugage is unsupported and you do not feel comfortable writing one, post an issue on github.
keymap_name.c.template has no keymap defined and all the keymap templates in one place.
If the keycodes are hard to figure out, /tmk_core/common/keycode.h has the whole list avalable.
Please drop the `KC_' for each keycode when using keycodes from `keycode.h'.


# Things TO-DO

- [ ] Flash NumLock led only when "numpad" layer is active
- [ ] Command (in terms of IS_COMMAND) to switch to no-leds mode
- [ ] Increase count of ACTION keys
- [ ] Fix command_state() onboard led: it should flash only when kbd in some specific mode (CONSOLE || MOUSE)
- [ ] ergodox_blink_all_leds() should save current state of leds, and restore after blink. initial state of all leds == off
- [ ] add support for pseudo-backlight (reversed LEDs) + docs/photo
- [ ] command to debug all LEDs (on/off/blink)
- [ ] proper (in-core) implementation of DEBUG_MATRIX_SCAN_RATE (non-Ergodox specific)
- [ ] proper (in-core) support for per-layer fn_actions[]
- [ ] create one-handed layouts, see
        http://half-qwerty.com/
        https://geekhack.org/index.php?topic=60165.0
        https://www.massdrop.com/ext/ergodox/?hash=e097c3b9932179055023d47e48b25f1d

