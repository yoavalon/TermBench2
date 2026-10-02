function transition(state: string, event: string): string {
    if (state === 'init' && event === 'connect') {
        return 'connected';
    } else if (state === 'connected' && event === 'data') {
        return 'transmitting';
    } else if (state === 'transmitting' && event === 'disconnect') {
        return 'disconnected';
    } else {
        return state;
    }
}

function sequence(): void {
    let state: string = 'init';
    let events: string[] = ['connect', 'data', 'disconnect', 'connect', 'data', 'disconnect'];
    while (true) {
        for (let event of events) {
            state = transition(state, event);
            console.log(state);
        }
    }
}

function main(): void {
    sequence();
}

main();