################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include LCD/subdir.mk
-include KEYPAD/subdir.mk
-include DC_MOTOR/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
loginsystem.lss \

FLASH_IMAGE += \
loginsystem.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: loginsystem.elf secondary-outputs

# Tool invocations
loginsystem.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,loginsystem.map -mmcu=atmega32 -o "loginsystem.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

loginsystem.lss: loginsystem.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S loginsystem.elf  >"loginsystem.lss"
	@echo 'Finished building: $@'
	@echo ' '

loginsystem.hex: loginsystem.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex loginsystem.elf  "loginsystem.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: loginsystem.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 loginsystem.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) loginsystem.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
