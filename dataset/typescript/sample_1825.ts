function process_connections(states: Set<string>, transitions: { [key: string]: string }, initial: string, final: Set<string>): string {
    let state = initial;
    for (let _ = 0; _ < 10; _++) {
        if (final.has(state)) {
            break;
        }
        state = transitions[state] || state;
    }
    return state;
}

process_connections(new Set(['a', 'b', 'c']), { 'a': 'b', 'b': 'c', 'c': 'a' }, 'a', new Set(['c']));