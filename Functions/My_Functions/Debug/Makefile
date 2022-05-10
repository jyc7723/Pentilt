################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../inc \
../scr


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../scr/GPIO.cpp \
../scr/main.cpp \
../scr/TIMER.cpp \
../scr/UART.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
scr/GPIO.o \
scr/main.o \
scr/TIMER.o \
scr/UART.o

OBJS_AS_ARGS +=  \
scr/GPIO.o \
scr/main.o \
scr/TIMER.o \
scr/UART.o

C_DEPS +=  \
scr/GPIO.d \
scr/main.d \
scr/TIMER.d \
scr/UART.d

C_DEPS_AS_ARGS +=  \
scr/GPIO.d \
scr/main.d \
scr/TIMER.d \
scr/UART.d

OUTPUT_FILE_PATH +=My_Functions.elf

OUTPUT_FILE_PATH_AS_ARGS +=My_Functions.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
scr/GPIO.o: ../scr/GPIO.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../inc"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega128a -B "C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128a" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

scr/main.o: ../scr/main.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../inc"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega128a -B "C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128a" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

scr/TIMER.o: ../scr/TIMER.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../inc"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega128a -B "C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128a" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

scr/UART.o: ../scr/UART.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 5.4.0
	$(QUOTE)C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG  -I"C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\include" -I"../inc"  -Og -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega128a -B "C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128a" -c -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 5.4.0
	$(QUOTE)C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="My_Functions.map" -Wl,-u,vfprintf -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mrelax -mmcu=atmega128a -B "C:\My program Files\IDE\AVRStudio\7.0\Packs\atmel\ATmega_DFP\1.6.364\gcc\dev\atmega128a" -lprintf_flt -lm  
	@echo Finished building target: $@
	"C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "My_Functions.elf" "My_Functions.hex"
	"C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "My_Functions.elf" "My_Functions.eep" || exit 0
	"C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "My_Functions.elf" > "My_Functions.lss"
	"C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "My_Functions.elf" "My_Functions.srec"
	"C:\My program Files\IDE\AVRStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "My_Functions.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "My_Functions.elf" "My_Functions.a" "My_Functions.hex" "My_Functions.lss" "My_Functions.eep" "My_Functions.map" "My_Functions.srec" "My_Functions.usersignatures"
	