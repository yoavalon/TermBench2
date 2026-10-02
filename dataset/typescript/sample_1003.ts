function node_verify(state: { status: string }, consensus: (state: { status: string }) => any): any {
    if (state['status'] === 'pending') {
        state['status'] = 'verified';
        return consensus(state);
    } else {
        return node_verify(state, consensus);
    }
}

function consensus(state: { status: string }): any {
    if (state['status'] === 'verified') {
        state['status'] = 'confirmed';
        return node_verify(state, consensus);
    } else {
        return consensus(state);
    }
}

function main() {
    const state = { status: 'pending' };
    node_verify(state, consensus);
}

main();