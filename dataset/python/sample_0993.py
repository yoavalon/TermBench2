def state_machine(state):
    if state == 'open':
        state_machine('established')
    elif state == 'established':
        state_machine('data_transfer')
    elif state == 'data_transfer':
        state_machine('closing')
    elif state == 'closing':
        state_machine('closed')
    elif state == 'closed':
        state_machine('open')
state_machine('open')