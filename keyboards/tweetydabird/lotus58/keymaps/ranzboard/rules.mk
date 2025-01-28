SPLIT_KEYBOARD = yes
OLED_ENABLE = yes

BOARD = GENERIC_RP_RP2040

# Enable custom RGB matrix configuration
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
ifeq ($(RGB_MATRIX_ENABLE),yes)
	SRC += ./rgb.c
endif

ENCODER_MAP_ENABLE = yes
AUTO_SHIFT_ENABLE = no


CONSOLE_ENABLE = yes

LTO_ENABLED = no
TAP_DANCE_ENABLE = no
COMBO_ENABLE = no
CAPS_WORD_ENABLE = no

BOOTMAGIC_ENABLE = yes

OS_DETECTION_ENABLE = yes

RGB_MATRIX_BREATHING = yes
RGB_MATRIX_DIGITAL_RAIN = yes
RGB_MATRIX_HUE_BREATHING = yes
RGB_MATRIX_SOLID_MULTISPLASH = yes
RGB_MATRIX_SOLID_REACTIVE = yes
RGB_MATRIX_RAINDROPS = yes
RGB_MATRIX_TYPING_HEATMAP = yes
RGB_MATRIX_SPLASH = yes

