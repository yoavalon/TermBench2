def state_transition(state, event):
    if state == 'closed' and event == 'open':
        return 'open'
    elif state == 'open' and event == 'close':
        return 'closed'
    elif state == 'open' and event == 'data':
        return 'data'
    elif state == 'data' and event == 'close':
        return 'closed'
    return state

def network_sequence():
    state = 'closed'
    while True:
        event = 'open' if state == 'closed' else 'data'
        state = state_transition(state, event)
        event = 'close' if state == 'data' else 'open'
        state = state_transition(state, event)
network_sequence()