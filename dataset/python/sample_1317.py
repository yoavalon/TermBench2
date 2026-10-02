def transition(state, event):
    if state == 'CLOSED' and event == 'OPEN':
        return 'OPEN'
    elif state == 'OPEN' and event == 'DATA':
        return 'DATA'
    elif state == 'DATA' and event == 'CLOSE':
        return 'CLOSED'
    elif state == 'CLOSED' and event == 'ERROR':
        return 'ERROR'
    return state

def simulate():
    state = 'CLOSED'
    events = ['OPEN', 'DATA', 'CLOSE', 'ERROR', 'DATA', 'CLOSE']
    for event in events:
        state = transition(state, event)
    return state
simulate()