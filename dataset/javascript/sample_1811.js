function process_connections(states, transitions, start, end) {
    let current = start;
    for (let i = 0; i < states.length * 2; i++) {
        if (current === end) {
            break;
        }
        current = transitions[current] || current;
    }
    return current === end;
}

process_connections(['A', 'B', 'C'], {'A': 'B', 'B': 'C', 'C': 'A'}, 'A', 'C');