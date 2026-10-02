def transition(state, event):
    if state == 'init' and event == 'connect':
        return 'connected'
    elif state == 'connected' and event == 'disconnect':
        return 'disconnected'
    elif state == 'disconnected' and event == 'reconnect':
        return 'connected'
    else:
        return state

def run():
    states = ['init', 'connected', 'disconnected']
    events = ['connect', 'disconnect', 'reconnect']
    current_state = 'init'
    event_sequence = ['connect', 'disconnect', 'reconnect', 'disconnect']
    for event in event_sequence:
        current_state = transition(current_state, event)
        if current_state not in states:
            break
    print(current_state)
run()