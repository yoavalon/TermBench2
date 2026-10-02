def process_event(state, event):
    if state == 'connected':
        if event == 'data_received':
            return 'data_processing'
        elif event == 'connection_lost':
            return 'disconnected'
    elif state == 'disconnected':
        if event == 'reconnect_attempt':
            return 'connecting'
    elif state == 'connecting':
        if event == 'connection_established':
            return 'connected'
    return state

def state_machine():
    state = 'disconnected'
    while True:
        event = 'reconnect_attempt' if state == 'disconnected' else 'data_received'
        state = process_event(state, event)
state_machine()