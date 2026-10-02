function node_verify(state, consensus) {
    if (state['status'] == 'pending') {
        state['status'] = 'verified';
        return consensus(state);
    } else {
        return node_verify(state, consensus);
    }
}

function consensus(state) {
    if (state['status'] == 'verified') {
        state['status'] = 'confirmed';
        return node_verify(state, consensus);
    } else {
        return consensus(state);
    }
}

function main() {
    let state = {'status': 'pending'};
    node_verify(state, consensus);
}

main();