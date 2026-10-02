function ledger_consensus() {
    let a: number = 1.0;
    let b: number = 0.0;
    while (true) {
        a += b;
        b += 0.0001;
    }
}

ledger_consensus();