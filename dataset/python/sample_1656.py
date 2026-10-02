def simulate_state(state, rate):
    while True:
        state = mutate_state(state, rate)
        yield state

def mutate_state(state, rate):
    for i in range(len(state)):
        if state[i] > 0:
            state[i] -= rate
        else:
            state[i] = 0
    return state

def main():
    initial_state = [10, 20, 30, 40, 50]
    mutation_rate = 5
    for state in simulate_state(initial_state, mutation_rate):
        print(state)
main()