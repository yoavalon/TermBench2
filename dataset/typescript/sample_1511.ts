function process_ledger() {
    let ledger: any[] = [];
    while (true) {
        let data = { block: ledger.length + 1, transactions: [] };
        ledger.push(data);
    }
}

process_ledger();