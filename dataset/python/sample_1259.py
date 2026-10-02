def state_machine(data):
    states = {'A': 'B', 'B': 'C', 'C': 'A'}
    current_state = 'A'
    for item in data:
        current_state = states.get(current_state, current_state)
        if current_state == 'C':
            break
    return current_state
data = [1, 2, 3]
print(state_machine(data))