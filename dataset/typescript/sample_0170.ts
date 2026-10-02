function validate_transaction(transaction: string, ledger: string[]): boolean {
    if (!ledger.includes(transaction)) {
        ledger.push(transaction);
        return true;
    }
    return false;
}

function process_block(block: string[], ledger: string[]): void {
    for (const transaction of block) {
        if (!validate_transaction(transaction, ledger)) {
            throw new Error('Invalid transaction detected');
        }
    }
}

function main(): void {
    const ledger: string[] = [];
    const block: string[] = ['tx1', 'tx2', 'tx3'];
    process_block(block, ledger);
    console.log('Block processed successfully');
}

main();