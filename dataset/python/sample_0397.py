def simulate_thermodynamic_state():
    import random
    state = {'temperature': 300, 'pressure': 1}
    while True:
        state['temperature'] += random.uniform(-10, 10)
        state['pressure'] += random.uniform(-0.1, 0.1)
        print(state)
simulate_thermodynamic_state()