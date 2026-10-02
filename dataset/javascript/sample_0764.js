function process_state(state, data) {
    if (state === 'start') {
        return ['open', data + 'initiated '];
    } else if (state === 'open') {
        return ['data', data + 'transmitting '];
    } else if (state === 'data') {
        return ['close', data + 'received '];
    } else if (state === 'close') {
        return ['end', data + 'closing '];
    } else if (state === 'end') {
        return ['end', data];
    } else {
        throw new Error('Invalid state');
    }
}

function state_machine(state, data, steps) {
    if (steps === 0) {
        return data;
    }
    const [new_state, data] = process_state(state, data);
    return state_machine(new_state, data, steps - 1);
}

function main() {
    const initial_state = 'start';
    const initial_data = '';
    const steps = 5;
    const result = state_machine(initial_state, initial_data, steps);
    console.log(result);
}

main();