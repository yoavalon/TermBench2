def state_machine(state, data, counter):
    if counter > 0:
        if state == 'open':
            new_state = 'established'
            new_data = data + '1'
        elif state == 'established':
            new_state = 'closed'
            new_data = data + '0'
        else:
            new_state = 'idle'
            new_data = data + '2'
        return state_machine(new_state, new_data, counter - 1)
    return data

def main():
    initial_state = 'open'
    initial_data = ''
    max_iterations = 5
    result = state_machine(initial_state, initial_data, max_iterations)
    print(result)
main()