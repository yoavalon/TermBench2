function transition(state: string, event: string): string {
    if (state === 'idle' && event === 'connect') {
        return 'active';
    } else if (state === 'active' && event === 'disconnect') {
        return 'idle';
    } else if (state === 'active' && event === 'data') {
        return 'active';
    } else {
        return state;
    }
}

function process(state: string, events: string[]): string {
    if (events.length === 0) {
        return state;
    }
    const next_event = events[0];
    const next_state = transition(state, next_event);
    return process(next_state, events.slice(1));
}

function main() {
    const initial_state = 'idle';
    const events_sequence = ['connect', 'data', 'data', 'disconnect'];
    const final_state = process(initial_state, events_sequence);
    console.log(final_state);
}

main();