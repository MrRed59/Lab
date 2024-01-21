# coding=utf-8
from bottle import route, run, template, request
from gpiozero import MCP3008, OutputDevice
from flask import Flask

app = Flask(__name__)

# Параметры для управления реле и термодатчиком
relay_pin = 17  # Пин, к которому подключено реле
setpoint = 25.0  # Уставка температуры в градусах Цельсия
relay = OutputDevice(relay_pin)
adc = MCP3008  # Канал, к которому подключено термосопротивление. АЦП = 0


def read_temperature():
    try:
        # Чтение значения с АЦП и преобразование его в температуру (пример)
        adc_value = adc.value
        voltage = adc_value * 3.3  # Напряжение АЦП 0...3.3 В
        low_v = (5 * 39.225) / (50 + 39.225)
        high_v = (5 * 92.775) / (50 + 92.775)
        range_v = high_v - low_v
        temperature_celsius = (voltage - 2.198) * (250 / 1.51) - 50
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
    app.run()
