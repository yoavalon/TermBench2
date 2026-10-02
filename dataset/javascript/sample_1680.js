function state_transition(state, event) {
    if (state === 'disconnected') {
        if (event === 'connect') {
            return 'connected';
        }
    } else if (state === 'connected') {
        if (event === 'disconnect') {
            return 'disconnected';
        } else if (event === 'data') {
            return 'data_received';
        }
    } else if (state === 'data_received') {
        if (event === 'acknowledge') {
            return 'connected';
        }
    }
    return state;
}

function* event_generator() {
    const events = ['connect', 'disconnect', 'data', 'acknowledge'];
    while (true) {
        for (const event of events) {
            yield event;
        }
    }
}

function main() {
    let current_state = 'disconnected';
    const eventGen = event_generator();
    while (true) {
        const event = eventGen.next().value;
        current_state = state_transition(current_state, event);
        console.log(`Event: ${event}, State: ${current_state}`);
    }
}

main();