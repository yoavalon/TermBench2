def cellular_automata(state, rule):
    size = len(state)
    next_state = [0] * size
    for i in range(size):
        left = state[(i - 1) % size]
        center = state[i]
        right = state[(i + 1) % size]
        index = left << 2 | center << 1 | right
        next_state[i] = rule >> index & 1
    return cellular_automata(next_state, rule)
rule = 30
initial_state = [0] * 10 + [1] + [0] * 10
cellular_automata(initial_state, rule)