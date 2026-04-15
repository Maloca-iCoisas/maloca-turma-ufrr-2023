import machine
import utime
import urandom

pressed = False
led = machine.Pin(15, machine.Pin.OUT)
button_left = machine.Pin(18, machine.Pin.IN, machine.Pin.PULL_DOWN)
button_right = machine.Pin(19, machine.Pin.IN, machine.Pin.PULL_DOWN)
fastest_button = None

def button_handler(pin):
    global pressed
    if not pressed:
        pressed=True
        global fastest_button
        fastest_button = pin
        global timer_reaction
        
        timer_reaction = utime.ticks_diff(utime.ticks_ms(), timer_start)
        # print("Seu tempo de reação foi " + str(timer_reaction) + " milisegundos!")
        # print("PARABÉNS JOGADOR!")

led.value(1)
utime.sleep(urandom.uniform(5, 10))
led.value(0)

timer_start = utime.ticks_ms()
button_left.irq(trigger=machine.Pin.IRQ_RISING, handler=button_handler)
button_right.irq(trigger=machine.Pin.IRQ_RISING, handler=button_handler)

while fastest_button is None:
    utime.sleep(1)
if fastest_button is button_left:
    print("Jogador da esquerda Venceu! Por " + str(timer_reaction) + " milisegundos")
elif fastest_button is button_right:
    print("Jogador da direita Venceu! Por " + str(timer_reaction) + " milisegundos")