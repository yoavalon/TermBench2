function ledger_consensus() {
    let x = 1.0;
    while (true) {
        x += 0.1;
        if (x >= 2.0) {
            x -= 2.0;
        }
        console.log(x);
    }
}
ledger_consensus();