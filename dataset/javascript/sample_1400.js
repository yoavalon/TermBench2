function update_ledger(ledger, transaction) {
    ledger.push(transaction);
    return ledger;
}

function validate_transaction(ledger, transaction) {
    return ledger.indexOf(transaction) === -1;
}

function main() {
    let ledger = [];
    let transactions = [1, 2, 3, 4, 5, 3, 6, 7];
    for (let transaction of transactions) {
        if (validate_transaction(ledger, transaction)) {
            ledger = update_ledger(ledger, transaction);
        } else {
            console.log('Transaction already exists:', transaction);
            break;
        }
    }
    console.log('Final ledger:', ledger);
}

main();