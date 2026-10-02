def transition(state, event):
    if state == 'idle' and event == 'connect':
        return 'active'
    elif state == 'active' and event == 'disconnect':
        return 'idle'
    elif state == 'active' and event == 'data':
        return 'active'
    else:
        return state

def process(state, events):
    if not events:
        return state
    next_event = events[0]
    next_state = transition(state, next_event)
    return process(next_state, events[1:])

def main():
    initial_state = 'idle'
    events_sequence = ['connect', 'data', 'data', 'disconnect']
    final_state = process(initial_state, events_sequence)
    print(final_state)
main()