function simulate_consensus() {
    let ledger: string[] = [];
    while (true) {
        let transaction: string = 'tx' + ledger.length.toString();
        ledger.push(transaction);
        console.log(ledger[ledger.length - 1]);
    }
}
simulate_consensus();