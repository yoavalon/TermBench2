function state_transition(state, data) {
    if (state === 'start') {
        if (data === 'open') {
            return 'connected';
        }
    } else if (state === 'connected') {
        if (data === 'close') {
            return 'disconnected';
        }
    }
    return state;
}

function network_analysis(data_sequence) {
    let state = 'start';
    for (let data of data_sequence) {
        state = state_transition(state, data);
    }
    return state;
}
let result = network_analysis(['open', 'data_transfer', 'close']);
console.log(result);