#include "r2.h"
#include "rgb_matrix_types.h"

led_config_t g_led_config = {{
                                {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24}, 
                                {NO_LED, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25}, 
                                {9, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, NO_LED, 51}, 
                                {8, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52}, 
                                {66, 67, 68, 69, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, 70, 71, 72, 73, 74}
                            },
                             {{4, 47}, {4, 45}, {4, 44}, {4, 43}, {4, 41}, {4, 40}, {4, 38}, {4, 37}, {5, 28}, {8, 18}, {11, 8}, {26, 9}, {38, 9}, {50, 8}, {62, 10}, {74, 12}, {86, 14}, {98, 16}, {118, 15}, {130, 13}, {142, 11}, {154, 9}, {167, 8}, {179, 9}, {197, 9}, {203, 19}, {188, 19}, {175, 19}, {163, 18}, {151, 20}, {139, 22}, {127, 24}, {115, 26}, {90, 25}, {78, 23}, {66, 21}, {54, 19}, {41, 19}, {26, 19}, {21, 29}, {42, 29}, {54, 29}, {66, 31}, {78, 34}, {90, 36}, {120, 36}, {132, 34}, {144, 31}, {156, 29}, {169, 29}, {181, 29}, {201, 29}, {207, 40}, {190, 40}, {178, 40}, {165, 40}, {153, 40}, {141, 42}, {129, 45}, {117, 47}, {94, 47}, {82, 45}, {70, 42}, {58, 40}, {45, 40}, {25, 40}, {19, 50}, {35, 50}, {62, 52}, {83, 56}, {130, 55}, {154, 51}, {178, 50}, {190, 50}, {202, 50}},
                             {2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4}};
typedef union {
    uint32_t raw;
    struct {
        bool rgb_abc;
        bool rgb_line;
        bool rgb_back;
        bool rgb_line07;
        int  rgb_line255;
    };
} user_config_t;

user_config_t user_config;

void          keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
    user_config.raw         = 0;
    user_config.rgb_abc     = false;
    user_config.rgb_line    = false;
    user_config.rgb_back    = false;
    user_config.rgb_line07  = false;
    user_config.rgb_line255 = 0;
    eeconfig_update_user(user_config.raw);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_F19://——————————轴灯
            if (record->event.pressed) {
                if (user_config.rgb_abc) {
                    user_config.rgb_abc = false;
                } else {
                    user_config.rgb_abc = true;
                }
                eeconfig_update_user(user_config.raw);
            }
            return true;
        case KC_F20://——————————静止
            if (record->event.pressed) {
                if (user_config.rgb_back) {
                    user_config.rgb_back = false;
                } else {
                    user_config.rgb_back = true;
                }
                eeconfig_update_user(user_config.raw);
            }
            return true;
        case KC_F21://——————————条灯
            if (record->event.pressed) {
                if (user_config.rgb_line) {
                    user_config.rgb_line = false;
                } else {
                    user_config.rgb_line = true;
                }
                eeconfig_update_user(user_config.raw);
            }
            return true;
        case KC_F22://——————————彩虹
            if (record->event.pressed) {
                if (user_config.rgb_line07) {
                    user_config.rgb_line07 = false;
                } else {
                    user_config.rgb_line07 = true;
                }
                eeconfig_update_user(user_config.raw);
            }
            return true;
        case KC_F23://——————————彩虹变化
            if (record->event.pressed) {
                if (user_config.rgb_line255 > 190) {
                    user_config.rgb_line255 -= 190;
                } else {
                    user_config.rgb_line255 += 7;
                }
                eeconfig_update_user(user_config.raw);
            }
            return true;
        default:
            return true;
    }
}

bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(39, 0, 255, 0);
    }

    if (user_config.rgb_abc) { // ————————————轴座开关
        for (uint8_t i = 8; i < 75; ++i) {
            if (i == 39 && host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color(39, 0, 255, 0);
            } else {
                rgb_matrix_set_color(i, 0, 0, 0);
            }
        }
    }
    if (user_config.rgb_back) { // ————————————底灯开关
        for (uint8_t i = 75; i < 118; ++i) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }
    if (user_config.rgb_line) { // ————————————灯条开关
        for (uint8_t i = 0; i < 8; ++i) {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    } else {
        if (user_config.rgb_line07) { // ————————————彩虹开关
            for (uint8_t i = 0; i < 8; ++i) {
                HSV hsv = {user_config.rgb_line255 + i * 10, 255, rgb_matrix_get_val()};//10
                RGB rgb = hsv_to_rgb(hsv);
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }
    return true;
}
