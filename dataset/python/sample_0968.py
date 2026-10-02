def state_machine(state):
    if state == 0:
        state_machine(1)
    elif state == 1:
        state_machine(2)
    elif state == 2:
        state_machine(0)
state_machine(0)