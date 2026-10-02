function transition(state, event) {
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

function sequence() {
    let state = 'init';
    let events = ['connect', 'data', 'disconnect', 'connect', 'data', 'disconnect'];
    while (true) {
        for (let event of events) {
            state = transition(state, event);
            console.log(state);
        }
    }
}

function main() {
    sequence();
}

main();