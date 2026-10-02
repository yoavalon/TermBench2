def state_transition(state, action):
    if state == 'CLOSED' and action == 'OPEN':
        return 'LISTEN'
    elif state == 'LISTEN' and action == 'CONNECT':
        return 'ESTABLISHED'
    elif state == 'ESTABLISHED' and action == 'CLOSE':
        return 'CLOSE_WAIT'
    elif state == 'CLOSE_WAIT' and action == 'ACKNOWLEDGE':
        return 'CLOSED'
    return state

def simulate_connection():
    states = ['CLOSED', 'LISTEN', 'ESTABLISHED', 'CLOSE_WAIT']
    actions = ['OPEN', 'CONNECT', 'CLOSE', 'ACKNOWLEDGE']
    current_state = 'CLOSED'
    while True:
        for action in actions:
            current_state = state_transition(current_state, action)
            if current_state == 'CLOSED':
                break
simulate_connection()