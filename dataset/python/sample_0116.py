def calculate_energy(state, boundary):
    energy = 0
    for key in state:
        energy += state[key] * boundary[key]
    return energy

def check_condition(energy, threshold):
    if energy > threshold:
        return True
    return False

def main():
    state = {'temperature': 300, 'pressure': 101325, 'volume': 0.0224}
    boundary = {'temperature': 0.001, 'pressure': -0.0001, 'volume': 0.001}
    threshold = 500
    energy = calculate_energy(state, boundary)
    condition_met = check_condition(energy, threshold)
    if condition_met:
        print('Condition met:', energy)
    else:
        print('Condition not met:', energy)
main()