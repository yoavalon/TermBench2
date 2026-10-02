function transition(state: string, action: string): string {
    if (state === 'idle' && action === 'connect') {
        return 'connected';
    } else if (state === 'connected' && action === 'send') {
        return 'data_sent';
    } else if (state === 'data_sent' && action === 'disconnect') {
        return 'disconnected';
    } else if (state === 'disconnected' && action === 'reconnect') {
        return 'reconnecting';
    } else if (state === 'reconnecting' && action === 'connect') {
        return 'connected';
    }
    return state;
}

function simulate_network(): void {
    let state = 'idle';
    const actions = ['connect', 'send', 'disconnect', 'reconnect'];
    while (true) {
        const action = actions.shift()!;
        state = transition(state, action);
        actions.push(action);
    }
}

simulate_network();