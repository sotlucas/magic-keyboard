import serial
import pyautogui
import time
import os

x = 229
y = 339

ArduinoSerial = serial.Serial('/dev/ttyACM0', 9600, timeout=None)
time.sleep(2)

pyautogui.moveTo(x, y, duration=1)
pyautogui.click(x, y)
flag = True

while True:
    incoming = str(ArduinoSerial.readline())
    print(incoming)

    if 'Stop' in incoming:
        print('\a')
        flag = not flag

    if flag:
        if 'Play' in incoming:
            pyautogui.press('space')

        if 'Right' in incoming:
            pyautogui.hotkey('shift', 'n')

        if 'Left' in incoming:
            pyautogui.hotkey('alt', 'left')
