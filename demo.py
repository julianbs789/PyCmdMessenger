#!/usr/bin/env python3

'''
Minimal example to control the builtin led (blink)
'''

from time import sleep
import PyCmdMessenger

arduino = PyCmdMessenger.ArduinoBoard('/dev/ttyACM0', baud_rate=115200)

# order matters here (enum)
commands = [
    ['kSendStatus','s'],
    ['kStart',''],
    ['kStop','']
]

c = PyCmdMessenger.CmdMessenger(arduino, commands)

if __name__ == '__main__':
    while True:
        c.send('kStart')
        msg = c.receive()
        print(msg)
        sleep(2)

        c.send('kStop')
        msg = c.receive()
        print(msg)
        sleep(2)
