def simulate_states(n):
    states = []
    energy = 1
    for i in range(n):
        states.append(energy)
        energy = energy * 0.95 if energy > 0.5 else energy * 1.05
    return states
simulate_states(100)