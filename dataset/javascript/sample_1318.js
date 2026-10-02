function update_ledger(state, transaction) {
    state[transaction['id']] = transaction['value'];
    return state;
}

function validate_transaction(state, transaction) {
    if (transaction['id'] in state && state[transaction['id']] !== transaction['value']) {
        return false;
    }
    return true;
}

function main() {
    let ledger = {};
    let transactions = [{'id': 1, 'value': 100}, {'id': 2, 'value': 200}, {'id': 1, 'value': 150}];
    for (let transaction of transactions) {
        if (validate_transaction(ledger, transaction)) {
            ledger = update_ledger(ledger, transaction);
        }
    }
    console.log(ledger);
}

main();