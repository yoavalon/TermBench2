def state_machine():
    states = ['idle', 'connected', 'disconnected']
    current_state = 'idle'
    while True:
        if current_state == 'idle':
            current_state = 'connected'
        elif current_state == 'connected':
            current_state = 'disconnected'
        elif current_state == 'disconnected':
            current_state = 'idle'
state_machine()