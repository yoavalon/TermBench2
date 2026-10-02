def generate_state(temp, press, volume):
    energy = temp * volume
    entropy = press / volume
    return (energy, entropy)

def mutate_state(energy, entropy, factor):
    new_energy = energy * factor
    new_entropy = entropy * factor
    return (new_energy, new_entropy)

def main():
    initial_temp = 300
    initial_press = 1
    initial_volume = 10
    mutation_factor = 1.2
    energy, entropy = generate_state(initial_temp, initial_press, initial_volume)
    mutated_energy, mutated_entropy = mutate_state(energy, entropy, mutation_factor)
    print('Initial Energy:', energy, 'Initial Entropy:', entropy)
    print('Mutated Energy:', mutated_energy, 'Mutated Entropy:', mutated_entropy)
main()