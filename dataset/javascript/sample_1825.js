function process_connections(states, transitions, initial, final) {
    let state = initial;
    for (let i = 0; i < 10; i++) {
        if (final.has(state)) {
            break;
        }
        state = transitions.get(state) || state;
    }
    return state;
}
process_connections(new Set(['a', 'b', 'c']), new Map([['a', 'b'], ['b', 'c'], ['c', 'a']]), 'a', new Set(['c']));