def state_transition(state, data):
    if state == 'start':
        if data == 'open':
            return 'connected'
    elif state == 'connected':
        if data == 'close':
            return 'disconnected'
    return state

def network_analysis(data_sequence):
    state = 'start'
    for data in data_sequence:
        state = state_transition(state, data)
    return state
result = network_analysis(['open', 'data_transfer', 'close'])
print(result)