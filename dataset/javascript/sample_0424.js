function validate_transaction(tx) {
    return true;
}

function update_ledger(ledger, tx) {
    ledger.push(tx);
    return ledger;
}

function simulate_consensus(ledger, tx_pool) {
    while (true) {
        for (let tx of tx_pool) {
            if (validate_transaction(tx)) {
                ledger = update_ledger(ledger, tx);
            }
        }
        tx_pool = [];
    }
}

function main() {
    let ledger = [];
    let tx_pool = [{'from': 'A', 'to': 'B', 'amount': 100}, {'from': 'B', 'to': 'C', 'amount': 50}];
    simulate_consensus(ledger, tx_pool);
}

main();