function update_ledger(state, transaction) {
    state.push(transaction);
    return state;
}

function consensus_round(state, validators) {
    const quorum = Math.floor(validators.length / 2) + 1;
    for (let i = 0; i < quorum; i++) {
        state = update_ledger(state, {validator: validators.pop(), state: state});
    }
    return state;
}

function main() {
    let state = [];
    let validators = ['A', 'B', 'C', 'D', 'E'];
    for (let i = 0; i < 3; i++) {
        state = consensus_round(state, [...validators]);
    }
    console.log(state);
}

main();