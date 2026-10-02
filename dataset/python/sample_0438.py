def state_change(state):
    if state == 'idle':
        return 'listening'
    elif state == 'listening':
        return 'connected'
    elif state == 'connected':
        return 'closing'
    elif state == 'closing':
        return 'idle'
    else:
        return 'error'

def network_protocol():
    current_state = 'idle'
    while True:
        current_state = state_change(current_state)
        print(current_state)
network_protocol()