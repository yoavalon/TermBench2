function update_state(state, frame) {
    state['frame'] += 1;
    state['data'].push(frame);
}

function check_boundary_conditions(state, max_frames) {
    if (state['frame'] >= max_frames) {
        return true;
    }
    return false;
}

function main() {
    const max_frames = 10;
    const state = {'frame': 0, 'data': []};
    while (!check_boundary_conditions(state, max_frames)) {
        const frame = {'id': state['frame'], 'value': 'data_frame'};
        update_state(state, frame);
    }
    console.log(state);
}

main();