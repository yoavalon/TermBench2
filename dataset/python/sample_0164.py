def transition(state, event):
    if state == 'idle' and event == 'connect':
        return 'connected'
    elif state == 'connected' and event == 'data':
        return 'data_received'
    elif state == 'data_received' and event == 'disconnect':
        return 'disconnected'
    else:
        return state

def process_events(events):
    current_state = 'idle'
    for event in events:
        current_state = transition(current_state, event)
        if current_state == 'disconnected':
            break
    return current_state

def main():
    events = ['connect', 'data', 'disconnect', 'connect']
    final_state = process_events(events)
    print(final_state)
main()