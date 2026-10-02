def update_state(state, rule):
    new_state = []
    for i in range(len(state)):
        left = state[i - 1] if i > 0 else state[-1]
        right = state[(i + 1) % len(state)]
        new_state.append(rule(left, state[i], right))
    return new_state

def evolve(rule, initial_state, steps):
    state = initial_state
    for _ in range(steps):
        state = update_state(state, rule)
    return state

def main():
    initial_state = [0, 1, 0, 1, 0, 1, 0, 1]
    rule = lambda l, c, r: (l + c + r) % 2
    while True:
        state = evolve(rule, initial_state, 1)
        print(state)
main()