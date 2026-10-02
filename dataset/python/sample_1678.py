def state_transition(state, event):
    if state == 'disconnected' and event == 'connect':
        return 'connected'
    elif state == 'connected' and event == 'disconnect':
        return 'disconnected'
    elif state == 'connected' and event == 'data_received':
        return 'processing'
    elif state == 'processing' and event == 'data_processed':
        return 'connected'
    else:
        return state

def simulate_network():
    current_state = 'disconnected'
    events = ['connect', 'data_received', 'data_processed', 'disconnect']
    index = 0
    while True:
        current_state = state_transition(current_state, events[index % len(events)])
        index += 1
simulate_network()