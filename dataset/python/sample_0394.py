def simulate_boundary_conditions():
    while True:
        state = [1, 2, 3, 4, 5]
        for i in range(len(state)):
            state[i] += 0.1
        print(state)
simulate_boundary_conditions()