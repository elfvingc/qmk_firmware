#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
  /* QWERTY
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +?\ |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  å   |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |LSHIFT|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ö  |  ä   |
  * |------+------+------+------+------+------|  Del  |    | BkSP  |------+------+------+------+------+------|
  * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LALT |LOWER | /Space  /       \Enter \  |RAISE |      | RALT |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,  KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_DEL,     KC_BSPC, KC_N,  KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                               KC_LGUI, KC_LALT, LOWER, KC_SPC,     KC_ENT,  RAISE, XXXXXXX, KC_RALT
  ),
  /* LOWER
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |   ´  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |  F12 |      |  @   |      |      |      |                    | HOME | PgDn | PgUp | END  |      | ¨ ^ ~|
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |LSHIFT|  !   |  "   |  #   |  $   |  %   |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      | ' * ´|
  * |------+------+------+------+------+------|  Del  |    | BkSp  |------+------+------+------+------+------|
  * |LCTRL | <> | | CUT  | Copy | Paste|      |-------|    |-------|CtrlLf|      |      |CtrlRg|      |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LALT |LOWER | /Space  /       \Enter \  |RAISE |      | RALT |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_LOWER] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_EQL,
    KC_F12,  XXXXXXX, SE_AT,   XXXXXXX, XXXXXXX, XXXXXXX,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, KC_RBRC,
    _______, SE_EXLM, SE_DQUO, SE_HASH, SE_DLR,  SE_PERC,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, KC_NUHS,
    _______, KC_NUBS, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
  ),
  /* RAISE
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |RGBTOG|RGBMOD|   7  |   8  |   9  |      |                    |      |      |      |      |      |   \  |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |   4  |   5  |   6  |      |                    |      |   {  |   }  |RGBHUI|RGBSAI|RGBVAI|
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |LSHIFT|   0  |   1  |   2  |   3  |      |-------.    ,-------|      |   (  |   )  |RGBHUD|RGBSAD|RGBVAD|
  * |------+------+------+------+------+------|  Caps |    | BkSp  |------+------+------+------+------+------|
  * |      |  |   | CUT  | Copy | Paste|      |-------|    |-------|      |   [  |   ]  |      |      |RShift|
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LGUI | LALT |LOWER | /Space  /       \Enter \  |RAISE |      | RALT |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_RAISE] = LAYOUT(
    RGB_TOG, RGB_MOD, KC_7,    KC_8,    KC_9,    XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SE_BSLS,
    XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX,                   XXXXXXX, SE_LCBR, SE_RCBR, RGB_HUI, RGB_SAI, RGB_VAI,
    _______, KC_0,    KC_1,    KC_2,    KC_3,    XXXXXXX,                   XXXXXXX, SE_LPRN, SE_RPRN, RGB_HUD, RGB_SAD, RGB_VAD,
    XXXXXXX, SE_PIPE, KC_CUT,  KC_COPY, KC_PSTE, XXXXXXX, KC_CAPS, _______, XXXXXXX, SE_LBRC, SE_RBRC, XXXXXXX, XXXXXXX, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
  ),
  /* ADJUST
  * ,-----------------------------------------.                    ,-----------------------------------------.
  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
  * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
  * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
  * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
  * `-----------------------------------------/       /     \      \-----------------------------------------'
  *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
  *                   |      |      |      |/       /         \      \ |      |      |      |
  *                   `----------------------------'           '------''--------------------'
  */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
