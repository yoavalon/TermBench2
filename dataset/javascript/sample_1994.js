function validate_transaction(amount, balance) {
    if (amount <= balance) {
        return true;
    }
    return false;
}

function process_transaction(amount, balance) {
    if (validate_transaction(amount, balance)) {
        return balance - amount;
    }
    return balance;
}

function update_ledger(transactions, ledger) {
    for (let i = 0; i < transactions.length; i++) {
        let transaction = transactions[i];
        let amount = transaction[0];
        let account = transaction[1];
        ledger[account] = process_transaction(amount, ledger[account]);
    }
    return ledger;
}

function main() {
    let ledger = {'A': 1000.0, 'B': 500.0};
    let transactions = [(150.0, 'A'), (200.0, 'B'), (300.0, 'A')];
    let updated_ledger = update_ledger(transactions, ledger);
    console.log(updated_ledger);
}

main();