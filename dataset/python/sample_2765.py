def cellular_automata(n):
    state = [0] * n
    state[n // 2] = 1
    while True:
        new_state = [0] * n
        for i in range(1, n - 1):
            new_state[i] = state[i - 1] ^ state[i + 1]
        state = new_state
cellular_automata(30)