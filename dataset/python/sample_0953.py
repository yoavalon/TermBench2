def state_machine(x):
    while True:
        x = 1 if x == 0 else 0
        state_machine(x)
state_machine(0)