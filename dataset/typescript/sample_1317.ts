function transition(state: string, event: string): string {
    if (state === 'CLOSED' && event === 'OPEN') {
        return 'OPEN';
    } else if (state === 'OPEN' && event === 'DATA') {
        return 'DATA';
    } else if (state === 'DATA' && event === 'CLOSE') {
        return 'CLOSED';
    } else if (state === 'CLOSED' && event === 'ERROR') {
        return 'ERROR';
    }
    return state;
}

function simulate(): string {
    let state = 'CLOSED';
    const events = ['OPEN', 'DATA', 'CLOSE', 'ERROR', 'DATA', 'CLOSE'];
    for (const event of events) {
        state = transition(state, event);
    }
    return state;
}

simulate();