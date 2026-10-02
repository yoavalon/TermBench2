def transition(state, event):
    if state == 'init' and event == 'connect':
        return 'connected'
    elif state == 'connected' and event == 'data':
        return 'transmitting'
    elif state == 'transmitting' and event == 'disconnect':
        return 'disconnected'
    else:
        return state

def sequence():
    state = 'init'
    events = ['connect', 'data', 'disconnect', 'connect', 'data', 'disconnect']
    while True:
        for event in events:
            state = transition(state, event)
            print(state)

def main():
    sequence()
main()