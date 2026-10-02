def state_machine():
    states = ['idle', 'connecting', 'connected', 'disconnecting']
    current_state = 'idle'
    while True:
        if current_state == 'idle':
            current_state = 'connecting'
        elif current_state == 'connecting':
            current_state = 'connected'
        elif current_state == 'connected':
            current_state = 'disconnecting'
        elif current_state == 'disconnecting':
            current_state = 'idle'
state_machine()