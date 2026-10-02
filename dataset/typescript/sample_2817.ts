function transition(state: string, event: string): string {
    if (state === 'init' && event === 'connect') {
        return 'connected';
    } else if (state === 'connected' && event === 'disconnect') {
        return 'disconnected';
    } else if (state === 'disconnected' && event === 'reconnect') {
        return 'connected';
    } else {
        return state;
    }
}

function* sequence(event_list: string[]): Generator<string> {
    let current_state = 'init';
    while (true) {
        for (const event of event_list) {
            current_state = transition(current_state, event);
            yield current_state;
        }
    }
}

function main() {
    const events = ['connect', 'disconnect', 'reconnect', 'connect', 'disconnect'];
    const stateGenerator = sequence(events);
    for (let state of stateGenerator) {
        console.log(state);
    }
}

main();