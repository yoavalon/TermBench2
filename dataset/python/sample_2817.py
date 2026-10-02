def transition(state, event):
    if state == 'init' and event == 'connect':
        return 'connected'
    elif state == 'connected' and event == 'disconnect':
        return 'disconnected'
    elif state == 'disconnected' and event == 'reconnect':
        return 'connected'
    else:
        return state

def sequence(event_list):
    current_state = 'init'
    while True:
        for event in event_list:
            current_state = transition(current_state, event)
            yield current_state

def main():
    events = ['connect', 'disconnect', 'reconnect', 'connect', 'disconnect']
    for state in sequence(events):
        print(state)
main()