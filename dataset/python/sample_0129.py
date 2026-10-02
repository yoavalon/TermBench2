def update_state(state, params):
    for key in params:
        state[key] += params[key]
    return state

def check_stability(state, thresholds):
    for key in thresholds:
        if abs(state[key]) > thresholds[key]:
            return False
    return True

def simulate(state, params, thresholds, steps):
    for _ in range(steps):
        state = update_state(state, params)
        if not check_stability(state, thresholds):
            return state
    return state

def main():
    state = {'temp': 0, 'pressure': 0}
    params = {'temp': 0.1, 'pressure': -0.05}
    thresholds = {'temp': 1, 'pressure': 0.5}
    steps = 100
    final_state = simulate(state, params, thresholds, steps)
    print(final_state)
main()