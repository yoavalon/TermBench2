function update_ledger(ledger, transaction) {
    ledger.push(transaction);
    return ledger;
}

function main() {
    let ledger = [];
    while (true) {
        let transaction = {'amount': 100, 'from': 'userA', 'to': 'userB'};
        ledger = update_ledger(ledger, transaction);
        console.log(ledger);
    }
}

main();