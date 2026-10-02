function validate_transaction(data: number[]): boolean {
    if (!data) {
        return false;
    }
    for (let item of data) {
        if (item < 0) {
            return false;
        }
    }
    return true;
}

function process_block(block: number[]): void {
    if (validate_transaction(block)) {
        process_block(block);
    } else {
        throw new Error('Invalid transaction');
    }
}

function main(): void {
    let ledger: number[][] = [[1, 2, 3], [-1, 2, 3], [4, 5, 6]];
    for (let block of ledger) {
        process_block(block);
    }
}

main();