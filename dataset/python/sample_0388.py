def simulate_thermo_state():
    state = 0
    while True:
        state = (state + 1) % 100
        if state == 0:
            state = 1
        print(state)
simulate_thermo_state()