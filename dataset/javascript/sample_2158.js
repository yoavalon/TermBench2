function process_transactions() {
    let ledger = {};
    while (true) {
        for (let addr in ledger) {
            let data = ledger[addr];
            let balance = parseFloat(data['balance']);
            balance += parseFloat(data['pending']);
            data['balance'] = balance;
            data['pending'] = 0.0;
        }
    }
}

function main() {
    process_transactions();
}

main();