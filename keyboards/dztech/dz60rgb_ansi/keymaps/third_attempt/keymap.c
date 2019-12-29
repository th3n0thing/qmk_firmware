#include QMK_KEYBOARD_H

//Number of taps for TT which toggles a layer
#define TAPPING_TOGGLE 2

//#define GUI_LFT RGUI_T(KC_LEFT)
#define MO_LEFT MT(MO(1), KC_LEFT)
#define ALT_DWN RALT_T(KC_DOWN)
#define CTL_RGT RCTL_T(KC_RGHT)
#define SFT_UP  RSFT_T(KC_UP)

enum custom_keycodes
{
  DSK_LFT = SAFE_RANGE,
  DSK_RGT,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  
    case DSK_LFT:
      if (record->event.pressed)
      {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT));
      } 
      break;
      
    case DSK_RGT:
      if (record->event.pressed)
      {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_RGHT));
      } 
      break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{

	[0] = LAYOUT_60_ansi(
	
	 KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  KC_BSPC,
	 KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_BSLS,
    MO(1),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  SFT_UP,
  KC_LCTL, KC_LGUI, KC_LALT,                    KC_SPC,                     TT(2), MO_LEFT, ALT_DWN, CTL_RGT),
	
	[1] = LAYOUT_60_ansi(
	
	 KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,   KC_DEL,
  _______, _______, _______, _______, _______, KC_PSCR, _______, _______, KC_HOME,  KC_END, _______, _______, DM_PLY1,  DM_PLY2,
  KC_TRNS, DSK_LFT, DSK_RGT, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, 
  KC_LSFT, _______, _______, _______, _______, _______, KC_MRWD, KC_MFFD, KC_VOLD, KC_VOLU, _______, _______, 
  KC_LCTL, _______, KC_LALT,                   KC_MPLY,                   _______, _______, _______, _______),
	
	[2] = LAYOUT_60_ansi(
	
	_______, _______, KC_PSLS, KC_PAST, KC_PMNS, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, DM_RSTP,
  _______,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, _______, _______, _______, _______, _______, _______, _______, DM_REC1, DM_REC2,
  _______,   KC_P4,   KC_P5,   KC_P6, KC_PENT, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,   KC_P1,   KC_P2,   KC_P3, KC_PENT, _______, _______, _______, _______, _______, _______, _______, 
  _______, _______,   KC_P0,                   KC_PDOT,                   KC_TRNS, _______, _______, _______)
  
};
