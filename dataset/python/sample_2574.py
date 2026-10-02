def update_state(state, rule):
    new_state = []
    for i in range(len(state)):
        left = state[i - 1] if i > 0 else state[-1]
        right = state[(i + 1) % len(state)]
        new_state.append(rule(left, state[i], right))
    return new_state

def cellular_automaton(steps, initial, rule):
    state = initial
    for _ in range(steps):
        state = update_state(state, rule)
    return state

def rule_conway(left, center, right):
    count = left + center + right
    return 1 if count == 3 else 0 if count == 2 else center

def main():
    initial_state = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1]
    steps = 5
    final_state = cellular_automaton(steps, initial_state, rule_conway)
    print(final_state)
main()