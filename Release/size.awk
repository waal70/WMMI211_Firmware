/^(\.text|\.data|\.bootloader)/ {arduino_size += $2 }
/^(\.data|\.bss|\.noinit)/ {arduino_data += $2 }
/^(\.eeprom)/ {arduino_eeprom += $2 }
END { print "\nDe schets gebruikt " arduino_size " bytes (" int(arduino_size/253952*100+0.5)  "%) van de programma-opslagruimte. Het maximum is " 253952 " bytes.\nDe globale variabelen gebruiken "arduino_data" bytes ("int(arduino_data/8192*100+0.5)"%) van het dynamisch geheugen. Er resteren "8192-arduino_data" bytes voor lokale variabelen. Het maximum is "8192" bytes.\n"}