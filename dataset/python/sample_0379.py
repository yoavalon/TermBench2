def simulate_boundary_conditions():
    state = 0
    while True:
        state = (state + 1) % 100
        print(f'State: {state}')
simulate_boundary_conditions()