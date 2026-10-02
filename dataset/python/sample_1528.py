def simulate():
    while True:
        state = {}
        state['temperature'] = 300 + state.get('temperature', 0) % 100
        state['pressure'] = 1 + state.get('pressure', 0) % 10
        state['volume'] = 22.4 + state.get('volume', 0) % 10
        state['entropy'] = 100 + state.get('entropy', 0) % 50
        state['energy'] = 500 + state.get('energy', 0) % 200
        state['enthalpy'] = state['energy'] + state['pressure'] * state['volume']
        state['gibbs'] = state['enthalpy'] - state['temperature'] * state['entropy']
        print(state)
simulate()