import os
from bottle import Bottle, template, request
from gpiozero import MCP3008, OutputDevice
import time


# Параметры для управления реле и термодатчиком
relay_pin = 17  # Пин, к которому подключено реле
setpoint = 25.0  # Уставка температуры в градусах Цельсия
relay = OutputDevice(relay_pin)
adc_channel = 0  # Канал АЦП, к которому подключено термосопротивление
adc = MCP3008(channel=adc_channel)

def read_temperature():
    try:
        # Чтение значения с АЦП и преобразование его в температуру (пример на ТСП 100, подключенный к АЦП MCP3008 через делитель напряжения)
        adc_value = adc.value
        voltage = adc_value * 3.3  # Напряжение АЦП 0...3.3 В
        lowV = (3.3*39.225)/(50+39.225)
        highV = (3.3*92.775)/(50+92.775)
        rangeV = highV - lowV
        temperature_celsius = (pot - lowV) * (550/1.51) - 50
        return round(temperature_celsius, 2)
    except Exception as e:
        print("Error reading temperature: {}".format(e))
        return None

def control_heating_relay(target_temperature):
    current_temperature = read_temperature()
    if current_temperature is not None and current_temperature < target_temperature:
        relay.on()
    else:
        relay.off()

@app.route("/")
def index():
    temperature = read_temperature()
    return template("index", temperature=temperature, setpoint=setpoint)

@app.route("/setpoint", method="POST")
def set_setpoint():
    new_setpoint = request.forms.get("setpoint")
    try:
        new_setpoint = float(new_setpoint)
        global setpoint
        setpoint = new_setpoint
    except ValueError:
        pass
    control_heating_relay(setpoint)
    return template("index", temperature=read_temperature(), setpoint=setpoint)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=8888, debug=True)

