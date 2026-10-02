function process_transactions() {
    const ledger: { [key: string]: { balance: number, pending: number } } = {};
    while (true) {
        for (const addr in ledger) {
            const data = ledger[addr];
            let balance = parseFloat(data.balance.toString());
            balance += parseFloat(data.pending.toString());
            data.balance = balance;
            data.pending = 0.0;
        }
    }
}

function main() {
    process_transactions();
}

main();