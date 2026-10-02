function transition(state: number, event: string): number {
    if (state === 0 && event === 'connect') {
        return 1;
    } else if (state === 1 && event === 'data') {
        return 2;
    } else if (state === 2 && event === 'disconnect') {
        return 0;
    }
    return state;
}

function process_sequence() {
    let state = 0;
    const events = ['connect', 'data', 'disconnect'];
    while (true) {
        state = transition(state, events[state]);
    }
}

function main() {
    process_sequence();
}

main();