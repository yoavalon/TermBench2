function ledger_consensus() {
    let ledger = [0];
    while (true) {
        ledger.push(ledger[ledger.length - 1] + 1);
        ledger.push(ledger[ledger.length - 2] - 1);
        ledger.push(ledger[ledger.length - 3] * 2);
        ledger.push(ledger[ledger.length - 4] // 3);
        ledger.push(ledger[ledger.length - 5] % 4);
    }
}

ledger_consensus();