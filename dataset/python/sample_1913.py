def simulate_temperature(state, precision):
    while True:
        state += 0.0001
        if round(state, precision) == round(state, precision + 1):
            break
    return state

def analyze_state(initial_state, target_precision):
    result = simulate_temperature(initial_state, target_precision)
    return result

def main():
    initial_value = 0.0
    precision_level = 4
    final_state = analyze_state(initial_value, precision_level)
    print(final_state)
main()