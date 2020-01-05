#include QMK_KEYBOARD_H

#define GUI_LFT RGUI_T(KC_LEFT)
#define ALT_DWN RALT_T(KC_DOWN)
#define CTL_RGT RCTL_T(KC_RGHT)
#define SFT_UP  RSFT_T(KC_UP)

enum custom_keycodes
{
  DSK_LFT = SAFE_RANGE,
  DSK_RGT,
  SLC_L2R,
  SLC_R2L,
  CTALDEL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  
    case DSK_LFT:
      if (record->event.pressed)
      {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_LGUI));
      } 
      break;
      
    case DSK_RGT:
      if (record->event.pressed)
      {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LCTL) SS_UP(X_LGUI));
      } 
      break;
      
    case SLC_L2R:
      if (record->event.pressed)
      {
        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_END) SS_UP(X_LSFT));
      } 
      break;
      
    case SLC_R2L:
      if (record->event.pressed)
      {
        SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_HOME) SS_UP(X_LSFT));
      } 
      break;
      
    case CTALDEL:
      if (record->event.pressed)
      {
        SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT) SS_TAP(X_DEL) SS_UP(X_LCTL) SS_UP(X_LALT));
      } 
      break;

  }
  return true;
};


    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ MO(1)│ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│Alt │MO3 │                        │ MO2│ GUI│ ALT│Ctrl│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘
     */
     

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

	[0] = LAYOUT_60_ansi(
	
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
  MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
  KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          SFT_UP,
  KC_LCTL, MO(1),   KC_LALT,                            KC_SPC,                             MO(2),   GUI_LFT, ALT_DWN, CTL_RGT),
  
	[1] = LAYOUT_60_ansi(
	
	KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
  KC_NO,   KC_HOME, KC_END,  KC_NO,   KC_NO,   KC_PSCR, KC_NO,   KC_NO,   KC_NO,   KC_VOLD, KC_VOLU, KC_NO,   DM_PLY1, DM_PLY2,
  KC_TRNS, DSK_LFT, DSK_RGT, KC_NO,   CTALDEL, KC_NO,   KC_NO,   KC_HOME, KC_END,  SLC_R2L, SLC_L2R, KC_NO,            KC_NO,   
  KC_LSFT,          SLC_R2L, SLC_L2R, KC_NO,   KC_NO,   KC_NO,   KC_PGUP, KC_PGDN, KC_NO,   KC_NO,   KC_NO,            KC_RSFT,   
  KC_LCTL, KC_TRNS, KC_LALT,                            KC_MPLY,                            KC_NO,   KC_RGUI, KC_RALT, KC_RCTL),
	
	[2] = LAYOUT_60_ansi(
	
	KC_NO,   KC_NO,   KC_PSLS, KC_PAST, KC_PMNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_TOG, KC_NO,   DM_RSTP,
  KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DM_REC1, DM_REC2,
  KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PENT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,  
  KC_NO,            KC_P1,   KC_P2,   KC_P3,   KC_PENT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,            KC_NO,   
  KC_NO,   KC_LGUI, KC_PDOT,                            KC_P0,                              KC_TRNS, KC_NO,   KC_NO,   KC_NO)
  
};
