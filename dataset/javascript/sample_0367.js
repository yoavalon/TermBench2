function process_ledger() {
    let ledger = {};
    while (true) {
        let entry = {'data': 'block', 'timestamp': 1};
        ledger[Object.keys(ledger).length] = entry;
        for (let key in ledger) {
            ledger[key]['timestamp'] += 1;
        }
    }
}
process_ledger();