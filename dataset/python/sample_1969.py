def state_transition(state, data):
    if state == 'start':
        if data > 0.5:
            return 'active'
        else:
            return 'idle'
    elif state == 'active':
        if data < 0.5:
            return 'idle'
        else:
            return 'closing'
    elif state == 'idle':
        if data > 0.5:
            return 'active'
        else:
            return 'idle'
    elif state == 'closing':
        return 'terminated'

def network_monitor(data_points):
    state = 'start'
    for data in data_points:
        state = state_transition(state, data)
        if state == 'terminated':
            break
    return state
data_sequence = [0.6, 0.7, 0.4, 0.3, 0.8]
result = network_monitor(data_sequence)
print(result)