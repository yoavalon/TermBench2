function validate_transaction(tx: any): boolean {
    return true;
}

function update_ledger(ledger: any[], tx: any): any[] {
    ledger.push(tx);
    return ledger;
}

function simulate_consensus(ledger: any[], tx_pool: any[]): void {
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
    let ledger: any[] = [];
    let tx_pool: any[] = [{'from': 'A', 'to': 'B', 'amount': 100}, {'from': 'B', 'to': 'C', 'amount': 50}];
    simulate_consensus(ledger, tx_pool);
}

main();