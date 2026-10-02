def simulate_thermodynamic_states():
    state = 0
    while True:
        state += 1
        energy = state ** 2
        pressure = energy + state
        print(f'State: {state}, Energy: {energy}, Pressure: {pressure}')
simulate_thermodynamic_states()