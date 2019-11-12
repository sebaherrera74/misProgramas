# Compile options

VERBOSE=n
OPT=g
USE_NANO=y
SEMIHOST=n
USE_FPU=y

# Libraries

USE_LPCOPEN=y
USE_SAPI=y
# For LCD connected via I2C PCF8574T I/O expander
DEFINES+=LCD_HD44780_I2C_PCF8574T
