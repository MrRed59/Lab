import os
from gpiozero import MCP3008, OutputDevice


# Параметры для управления реле и термодатчиком
adc_channel = 0  # Канал АЦП, к которому подключено термосопротивление
adc = MCP3008(channel=adc_channel)

def read_temperature():
    try:
        # Чтение значения с АЦП и преобразование его в температуру (пример)
        adc_value = adc.value
        voltage = adc_value * 3.3  # Напряжение АЦП 0...3.3 В
        lowV = (5*39.225)/(50+39.225)
        highV = (5*92.775)/(50+92.775)
        rangeV = highV - lowV
        temperature_celsius = (pot - 2.198)
        temperature_celsius = value * (250/1.51) - 50
        return round(temperature_celsius, 2)
    except Exception as e:
        print("Error reading temperature: {}".format(e))
        return None

