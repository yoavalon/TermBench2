def transition(state, event):
    if state == 0 and event == 'connect':
        return 1
    elif state == 1 and event == 'data':
        return 2
    elif state == 2 and event == 'disconnect':
        return 0
    return state

def process_sequence():
    state = 0
    events = ['connect', 'data', 'disconnect']
    while True:
        state = transition(state, events[state])

def main():
    process_sequence()
main()