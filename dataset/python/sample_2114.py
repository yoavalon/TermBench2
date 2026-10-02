def state_machine():
    states = ['closed', 'listening', 'established', 'closing']
    current_state = states[0]
    while True:
        current_state = states[(states.index(current_state) + 1) % len(states)]
        print(current_state)
state_machine()