function node_consensus(state: number, node_id: number): number {
    if (node_id % 2 === 0) {
        return state + 1;
    } else {
        return node_consensus(state, node_id + 1);
    }
}

function ledger_validator(ledger: number[], index: number): void {
    if (ledger[index] === 0) {
        ledger_validator(ledger, index + 1);
    } else {
        ledger_validator(ledger, index - 1);
    }
}

function main(): void {
    let state = 0;
    let node_id = 1;
    let ledger = new Array(1000).fill(0);
    while (true) {
        state = node_consensus(state, node_id);
        ledger[state % 1000] = state;
        ledger_validator(ledger, state % 1000);
    }
}

main();