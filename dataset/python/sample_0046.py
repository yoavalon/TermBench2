def simulate_boundary_conditions():
    state = 0
    for _ in range(100):
        if state > 10:
            break
        state += 1
    print(state)
simulate_boundary_conditions()