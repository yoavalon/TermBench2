function simulate_consensus() {
    let ledger = [];
    while (true) {
        let transaction = 'tx' + ledger.length;
        ledger.push(transaction);
        console.log(ledger[ledger.length - 1]);
    }
}
simulate_consensus();