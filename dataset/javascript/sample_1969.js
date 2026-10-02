function state_transition(state, data) {
    if (state === 'start') {
        if (data > 0.5) {
            return 'active';
        } else {
            return 'idle';
        }
    } else if (state === 'active') {
        if (data < 0.5) {
            return 'idle';
        } else {
            return 'closing';
        }
    } else if (state === 'idle') {
        if (data > 0.5) {
            return 'active';
        } else {
            return 'idle';
        }
    } else if (state === 'closing') {
        return 'terminated';
    }
}

function network_monitor(data_points) {
    let state = 'start';
    for (let data of data_points) {
        state = state_transition(state, data);
        if (state === 'terminated') {
            break;
        }
    }
    return state;
}

let data_sequence = [0.6, 0.7, 0.4, 0.3, 0.8];
let result = network_monitor(data_sequence);
console.log(result);