function update_ledger(state: { [key: string]: string }, block: { hash: string, data: string }): { [key: string]: string } {
    let new_state = { ...state };
    new_state[block.hash] = block.data;
    return new_state;
}

function verify_block(block: { hash: string, data: string, prev_hash: string }, prev_hash: string): boolean {
    return block.prev_hash === prev_hash;
}

function process_transaction(state: { [key: string]: string }, block: { hash: string, data: string, prev_hash: string }): { [key: string]: string } {
    if (verify_block(block, Object.keys(state)[Object.keys(state).length - 1])) {
        return update_ledger(state, block);
    }
    return state;
}

function main() {
    let ledger: { [key: string]: string } = { 'genesis': 'initial_state' };
    while (true) {
        let new_block = { 'hash': 'block_hash', 'data': 'transaction_data', 'prev_hash': Object.keys(ledger)[Object.keys(ledger).length - 1] };
        ledger = process_transaction(ledger, new_block);
    }
}

main();