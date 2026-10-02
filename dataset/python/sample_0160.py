def state_machine(state, event):
    if state == 'start' and event == 'connect':
        return 'connected'
    elif state == 'connected' and event == 'disconnect':
        return 'disconnected'
    elif state == 'disconnected' and event == 'connect':
        return 'connected'
    elif state == 'connected' and event == 'data':
        return 'processing'
    elif state == 'processing' and event == 'complete':
        return 'connected'
    elif state == 'connected' and event == 'error':
        return 'error'
    elif state == 'error' and event == 'recover':
        return 'connected'
    return state

def process_events():
    states = ['start', 'connected', 'disconnected', 'processing', 'error']
    events = ['connect', 'disconnect', 'data', 'complete', 'error', 'recover']
    current_state = 'start'
    for event in events:
        current_state = state_machine(current_state, event)
        if current_state == 'error':
            break
process_events()