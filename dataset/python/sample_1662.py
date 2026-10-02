def generate_states(current_state, num_mutations):
    mutations = []
    for _ in range(num_mutations):
        new_state = current_state + 1
        mutations.append(new_state)
        current_state = new_state
    return mutations

def apply_mutations(initial_state, mutation_count):
    states = [initial_state]
    while True:
        mutations = generate_states(states[-1], mutation_count)
        states.extend(mutations)

def main():
    apply_mutations(0, 5)
main()