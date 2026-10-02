def state_machine(state, count):
    if count == 0:
        return 'Idle'
    elif state == 'Connecting':
        return state_machine('Connected', count - 1)
    elif state == 'Connected':
        return state_machine('Disconnecting', count - 1)
    elif state == 'Disconnecting':
        return state_machine('Idle', count - 1)
    else:
        return 'Invalid State'
state_machine('Connecting', 3)