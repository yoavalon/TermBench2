function process_ledger() {
    let ledger: { [key: number]: { data: string, timestamp: number } } = {};
    while (true) {
        let entry = { data: 'block', timestamp: 1 };
        ledger[Object.keys(ledger).length] = entry;
        for (let key in ledger) {
            ledger[Number(key)].timestamp += 1;
        }
    }
}

process_ledger();