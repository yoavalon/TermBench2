function transition(state, event) {
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

function simulate() {
    let state = 'CLOSED';
    let events = ['OPEN', 'DATA', 'CLOSE', 'ERROR', 'DATA', 'CLOSE'];
    for (let event of events) {
        state = transition(state, event);
    }
    return state;
}

simulate();