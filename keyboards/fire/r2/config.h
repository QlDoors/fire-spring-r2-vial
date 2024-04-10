#pragma once

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15
#define MATRIX_ROW_PINS { C7, C6, B6, B5, D0}
#define MATRIX_COL_PINS { D2, D3, D5, D4, D6, D7, B4, F7, F6, F5, F4, F1, F0, B0, B1}

//#define VIAL_KEYBOARD_UID {0xCA, 0xD8, 0xDE, 0x57, 0xCE, 0xA2, 0x74, 0xB7}

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define DEBOUNCE 5

/* RGB matrix key backlighting */
#define WS2812_DI_PIN D1
#define RGB_MATRIX_LED_COUNT 75
#define RGB_MATRIX_TIMEOUT 0 // number of milliseconds to wait until rgb automatically turns off
#define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
#define RGB_MATRIX_LED_PROCESS_LIMIT 75 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_ALL // Sets the default mode, if none has been set
#define RGB_MATRIX_DEFAULT_HUE 0 // Sets the default hue value, if none has been set
#define RGB_MATRIX_DEFAULT_SAT 255 // Sets the default saturation value, if none has been set
#define RGB_MATRIX_DEFAULT_VAL 200 // Sets the default brightness value, if none has been set
#define RGB_MATRIX_DEFAULT_SPD 170 // Sets the default animation speed, if none has been set
#define RGB_TRIGGER_ON_KEYDOWN      // Triggers RGB keypress events on key down. This makes RGB control feel more responsive. This may cause RGB to not function properly on some boards
#define RGB_MATRIX_CENTER { 112, 32 }

#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
//enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
//enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
// #define ENABLE_RGB_MATRIX_SPLASH
// #define ENABLE_RGB_MATRIX_MULTISPLASH
// #define ENABLE_RGB_MATRIX_SOLID_SPLASH
// #define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH

#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

#define RGB_MATRIX_SOLID_REACTIVE_GRADIENT_MODE