def process_connection(state, event):
    if state == 'idle' and event == 'connect':
        return 'connected'
    elif state == 'connected' and event == 'data':
        return 'data_received'
    elif state == 'data_received' and event == 'disconnect':
        return 'disconnected'
    return state

def manage_state_machine():
    state = 'idle'
    events = ['connect', 'data', 'disconnect']
    for event in events:
        state = process_connection(state, event)
        if state == 'disconnected':
            break
manage_state_machine()