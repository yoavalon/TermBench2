function process_connections(states: string[], transitions: { [key: string]: string }, start: string, end: string): boolean {
    let current = start;
    for (let i = 0; i < states.length * 2; i++) {
        if (current === end) {
            break;
        }
        current = transitions[current] || current;
    }
    return current === end;
}

process_connections(['A', 'B', 'C'], { 'A': 'B', 'B': 'C', 'C': 'A' }, 'A', 'C');