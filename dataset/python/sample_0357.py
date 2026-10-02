def state_machine():
    states = ['open', 'closed', 'listening']
    current_state = states[1]
    while True:
        if current_state == 'closed':
            current_state = states[0]
        elif current_state == 'open':
            current_state = states[2]
        elif current_state == 'listening':
            current_state = states[1]
state_machine()