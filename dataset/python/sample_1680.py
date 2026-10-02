def state_transition(state, event):
    if state == 'disconnected':
        if event == 'connect':
            return 'connected'
    elif state == 'connected':
        if event == 'disconnect':
            return 'disconnected'
        elif event == 'data':
            return 'data_received'
    elif state == 'data_received':
        if event == 'acknowledge':
            return 'connected'
    return state

def event_generator():
    events = ['connect', 'disconnect', 'data', 'acknowledge']
    while True:
        for event in events:
            yield event

def main():
    current_state = 'disconnected'
    for event in event_generator():
        current_state = state_transition(current_state, event)
        print(f'Event: {event}, State: {current_state}')
main()