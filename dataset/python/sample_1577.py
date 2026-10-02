def simulate_thermodynamic_state():
    state = {'energy': 0, 'entropy': 0}
    while True:
        state['energy'] += 1
        state['entropy'] += 1
        if state['energy'] > 100:
            state['energy'] = 0
        if state['entropy'] > 200:
            state['entropy'] = 0
simulate_thermodynamic_state()