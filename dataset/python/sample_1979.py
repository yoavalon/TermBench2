def state_transition(state, precision):
    if state == 0:
        return 1 if precision > 0.5 else 2
    elif state == 1:
        return 0 if precision < 0.5 else 3
    elif state == 2:
        return 3 if precision > 0.5 else 0
    elif state == 3:
        return 2 if precision < 0.5 else 0

def network_analysis(precisions):
    state = 0
    for precision in precisions:
        state = state_transition(state, precision)
    return state

def main():
    data = [0.7, 0.3, 0.6, 0.4, 0.8]
    result = network_analysis(data)
    print(result)
main()