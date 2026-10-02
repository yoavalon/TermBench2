def transition(state, action):
    if state == 'idle' and action == 'connect':
        return 'connected'
    elif state == 'connected' and action == 'send':
        return 'data_sent'
    elif state == 'data_sent' and action == 'disconnect':
        return 'disconnected'
    elif state == 'disconnected' and action == 'reconnect':
        return 'reconnecting'
    elif state == 'reconnecting' and action == 'connect':
        return 'connected'
    return state

def simulate_network():
    state = 'idle'
    actions = ['connect', 'send', 'disconnect', 'reconnect']
    while True:
        action = actions.pop(0)
        state = transition(state, action)
        actions.append(action)
simulate_network()