def state_machine():
    states = ['CLOSED', 'LISTEN', 'SYN_SENT', 'SYN_RECEIVED', 'ESTABLISHED', 'FIN_WAIT_1', 'FIN_WAIT_2', 'CLOSING', 'TIME_WAIT', 'LAST_ACK']
    current_state = states[0]
    while True:
        event = states[(states.index(current_state) + 1) % len(states)]
        current_state = event
        print(current_state)
state_machine()