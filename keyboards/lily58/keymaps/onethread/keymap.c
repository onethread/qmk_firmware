#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
  _COLEMAKDH = 0,
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAVR,
  _NUMR,
  _NUMPADR,
  _SYMR,
  _NAVL,
  _MOUL,
  _NUML,
  _FUNL,
  _MEDL,
  _ADJUST,
};

enum custom_keycodes {
  // Layer Macros
  CLMKDH = SAFE_RANGE,
  QWERTY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* COLEMAK-DH
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |Delete|   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | LAlt | LGUI |BackSP| /  Tab  /       \Enter \  |Space | NAVL | FUNL |
     *                   |      |      |NUMR  |/ SYMR  /         \ MOUL \ |MEDL  |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_COLEMAKDH] = LAYOUT(
        KC_GRV,     KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                                       KC_6,               KC_7,           KC_8,           KC_9,           KC_0,               KC_MINUS, \
        KC_DEL,     KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,                                                       KC_J,               KC_L,           KC_U,           KC_Y,           KC_SCLN,            KC_BSLS, \
        KC_ESC,     LCTL_T(KC_A),   LALT_T(KC_R),   LGUI_T(KC_S),   LSFT_T(KC_T),   KC_G,                                                       KC_M,               RSFT_T(KC_N),   RGUI_T(KC_E),   LALT_T(KC_I),   RCTL_T(KC_O),       KC_QUOT, \
        KC_LSFT,    KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,               KC_LBRC,            KC_RBRC,            KC_K,               KC_H,           KC_COMM,        KC_DOT,         KC_SLSH,            KC_RSFT, \
                                                    KC_LALT,        KC_LGUI,        LT(_NUMR, KC_BSPC), LT(_NAVL, KC_TAB),  LT(_MOUL, KC_ENT),  LT(_SYMR, KC_SPC),  MO(_MEDL),      MO(_FUNL) \
    ),

    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |Delete|   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   | NUMR | LGUI |BackSP| /  Tab  /       \Enter \  |Space | NAVL | FUNL |
     *                   |      |      |      |/ SYMR  /         \ MOUL \ |MEDL  |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_QWERTY] = LAYOUT( \
        KC_GRV,     KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                                       KC_6,               KC_7,           KC_8,           KC_9,           KC_0,               KC_MINUS, \
        KC_DEL,     KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                                       KC_Y,               KC_U,           KC_I,           KC_O,           KC_P,               KC_BSLS, \
        KC_ESC,     LCTL_T(KC_A),   LALT_T(KC_S),   LGUI_T(KC_D),   LSFT_T(KC_F),   KC_G,                                                       KC_H,               RSFT_T(KC_J),   RGUI_T(KC_K),   LALT_T(KC_L),   RCTL_T(KC_SCLN),    KC_QUOT, \
        KC_LSFT,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,               KC_LBRC,            KC_RBRC,            KC_N,               KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,            KC_RSFT, \
                                                    MO(_NUMR),   KC_LGUI,        LT(_NUMR, KC_BSPC), LT(_NAVL, KC_TAB),  LT(_MOUL, KC_ENT),  LT(_SYMR, KC_SPC), MO(_MEDL),      MO(_FUNL) \
    ),

    /* LOWER
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |   ~  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |   -  |   +  |   {  |   }  |   |  |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |      |      |      | /       /       \      \  |      |      |      |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_LOWER] = LAYOUT( \
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,\
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, \
        _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
                                   _______, _______, _______, _______, _______, _______, _______, _______\
    ),
    /* RAISE
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |   _  |   =  |   [  |   ]  |   \  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /       /       \      \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */

    [_RAISE] = LAYOUT( \
        _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
        _______, _______, _______, _______, _______, _______,                     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
        _______, _______, _______, _______, _______, _______,  _______, _______,  _______, KC_UNDS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                                    _______, _______, _______,  _______, _______,  _______, _______, _______ \
    ),

    /* NAV RIGHT
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      | LCtl | LAlt | LGUI |LShift|      |-------.    ,-------|      | Left | Down |  Up  |Right |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- |      |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |      |      |      | /       /       \      \  |      |      |      |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_NAVR] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, \
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                   XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                   _______, _______, _______, _______, _______,  _______, _______, _______ \
    ),

    [_NUMR] = LAYOUT(
        XXXXXXX, XXXXXXX,       XXXXXXX,        XXXXXXX,        XXXXXXX,        XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
        XXXXXXX, XXXXXXX,       XXXXXXX,        XXXXXXX,        KC_LBRC,        XXXXXXX,                   KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, _______, _______, \
        XXXXXXX, LCTL_T(KC_1),  LALT_T(KC_2),   LGUI_T(KC_3),   LSFT_T(KC_4),   XXXXXXX,                   KC_MINS, RSFT_T(KC_7),   RGUI_T(KC_8),   LALT_T(KC_9),   RCTL_T(KC_0), _______, \
        XXXXXXX, KC_GRV,        XXXXXXX,        XXXXXXX,        KC_5,           XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_6,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
                                                _______,        _______,        _______, _______, _______, _______, KC_LBRC, KC_RBRC  \
    ),

    [_NUMPADR] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                   KC_MINS, KC_4,    KC_5,    KC_6,    KC_PLUS, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, XXXXXXX, \
                                   _______, _______, _______, _______, _______, KC_0,    KC_COMM, KC_DOT    \
    ),

    [_SYMR] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSLS, \
        XXXXXXX, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, XXXXXXX,                   KC_MINS, KC_DLR,  KC_PERC, KC_CIRC, KC_EQL,  KC_QUOT, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_SLSH, XXXXXXX, \
                                   _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, _______  \
    ),
    [_NAVL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,                   XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                   _______, _______, _______, _______, LT(_ADJUST, KC_ENT), _______, _______, _______  \
    ),

    [_MOUL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                   XXXXXXX, KC_BTN3, KC_BTN1, LT(_ADJUST, KC_BTN2),  _______, _______, _______, _______  \
    ),

    [_NUML] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_MINS, KC_4,    KC_5,    KC_6,    KC_PLUS,                   XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXXXXX, \
        XXXXXXX, KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                   _______, KC_COMM, KC_DOT,  _______, _______, _______, _______, _______  \
    ),

    [_FUNL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   XXXXXXX, KC_RSFT, KC_RGUI, KC_LALT, KC_RCTL, XXXXXXX, \
        XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                   _______, _______, _______, _______, _______, _______, _______, _______  \
    ),
    [_MEDL] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, KC_BRMD, KC_BRMU, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, KC_MPRV, KC__VOLDOWN, KC__VOLUP, KC_MNXT, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                   _______, _______, KC__MUTE, KC_MPLY, _______, _______, _______, _______  \
    ),

        /* ADJUST
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |      |      |      |QWERTY|CLMKDH|      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   |      |      |      | /       /       \      \  |      |      |      |
    *                   |      |      |      |/       /         \      \ |      |      |      |
    *                   `----------------------------'           '------''--------------------'
    */
    [_ADJUST] = LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,  CLMKDH,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                                   _______, _______, _______, _______, _______, _______, _______, _______  \
    ),

};


//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

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

void oled_task_user(void) {
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
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
      case CLMKDH:
        if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAKDH);
        }
        return false;
    case QWERTY:
        if (record-> event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
        }
        return false;
    case LT(_SYMR, KC_TAB):
    case LT(_MOUL, KC_ENT):
        update_tri_layer(_SYMR, _MOUL, _ADJUST);
        return true;
    default:
        return true;
  }
}
