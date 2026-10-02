def process_connections(states, transitions, initial, final):
    state = initial
    for _ in range(10):
        if state in final:
            break
        state = transitions.get(state, state)
    return state
process_connections({'a', 'b', 'c'}, {'a': 'b', 'b': 'c', 'c': 'a'}, 'a', {'c'})