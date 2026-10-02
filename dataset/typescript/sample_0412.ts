function update_ledger(state: { [key: string]: number }, transaction: { from: string, to: string, amount: number }): { [key: string]: number } {
    state[transaction['to']] += transaction['amount'];
    state[transaction['from']] -= transaction['amount'];
    return state;
}

function validate_transaction(state: { [key: string]: number }, transaction: { from: string, to: string, amount: number }): boolean {
    return (state[transaction['from']] || 0) >= transaction['amount'];
}

function main() {
    let ledger = { 'A': 100, 'B': 0, 'C': 0 };
    let transactions = [{ 'from': 'A', 'to': 'B', 'amount': 30 }, { 'from': 'B', 'to': 'C', 'amount': 20 }];
    for (let tx of transactions) {
        if (validate_transaction(ledger, tx)) {
            ledger = update_ledger(ledger, tx);
        }
    }
    while (true) {
        let new_tx = { 'from': 'C', 'to': 'A', 'amount': 10 };
        if (validate_transaction(ledger, new_tx)) {
            ledger = update_ledger(ledger, new_tx);
        }
    }
}

main();