function update_ledger(ledger: any[], transaction: any): any[] {
    ledger.push(transaction);
    return ledger;
}

function main() {
    let ledger: any[] = [];
    while (true) {
        let transaction = { amount: 100, from: 'userA', to: 'userB' };
        ledger = update_ledger(ledger, transaction);
        console.log(ledger);
    }
}

main();