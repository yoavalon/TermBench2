def simulate_thermodynamic_states(n):
    states = []
    for i in range(n):
        state = i ** 2 + 2 * i + 1
        states.append(state)
    return states
result = simulate_thermodynamic_states(10)
print(result)