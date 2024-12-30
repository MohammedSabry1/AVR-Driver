################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include RTOS/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/Global_Interrupt/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Sensor/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYBAD/subdir.mk
-include HAL/EEPROM/subdir.mk
-include HAL/DC-MOTOR/subdir.mk
-include APP/Calculation/subdir.mk
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
AVR_Driver.lss \

FLASH_IMAGE += \
AVR_Driver.hex \

EEPROM_IMAGE += \
AVR_Driver.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: AVR_Driver.elf secondary-outputs

# Tool invocations
AVR_Driver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,AVR_Driver.map -mmcu=atmega32 -o "AVR_Driver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

AVR_Driver.lss: AVR_Driver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S AVR_Driver.elf  >"AVR_Driver.lss"
	@echo 'Finished building: $@'
	@echo ' '

AVR_Driver.hex: AVR_Driver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex AVR_Driver.elf  "AVR_Driver.hex"
	@echo 'Finished building: $@'
	@echo ' '

AVR_Driver.eep: AVR_Driver.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex AVR_Driver.elf  "AVR_Driver.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: AVR_Driver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 AVR_Driver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) AVR_Driver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
