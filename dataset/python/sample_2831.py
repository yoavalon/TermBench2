def transition(state, event):
    if state == 0:
        return 1 if event == 'open' else state
    elif state == 1:
        return 2 if event == 'data' else state
    elif state == 2:
        return 3 if event == 'close' else state
    else:
        return 0

def simulate():
    state = 0
    while True:
        state = transition(state, 'open')
        state = transition(state, 'data')
        state = transition(state, 'close')
simulate()