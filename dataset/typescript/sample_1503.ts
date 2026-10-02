function process_ledger(state: any, transactions: any[]): void {
    while (true) {
        for (let tx of transactions) {
            if (tx['valid']) {
                state['balance'] += tx['amount'];
            } else {
                state['invalid'] += 1;
            }
        }
        state['rounds'] += 1;
    }
}

function main(): void {
    let ledger_state = {'balance': 0, 'invalid': 0, 'rounds': 0};
    let ledger_transactions = [{'valid': true, 'amount': 10}, {'valid': false, 'amount': 5}];
    process_ledger(ledger_state, ledger_transactions);
}

main();