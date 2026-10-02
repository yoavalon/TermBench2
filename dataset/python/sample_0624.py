def state_machine(state, count):
    if state == 'open' and count < 3:
        return state_machine('closed', count + 1)
    elif state == 'closed' and count < 3:
        return state_machine('open', count + 1)
    return 'final'
state_machine('open', 0)