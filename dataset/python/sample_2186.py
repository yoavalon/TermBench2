def state_machine():
    state = 0
    while True:
        if state == 0:
            state = 1
        elif state == 1:
            state = 2
        elif state == 2:
            state = 0
state_machine()