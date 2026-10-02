function process_transaction(block: number[], transaction: number): number[] {
    block.push(transaction);
    return block;
}

function calculate_consensus(block: number[]): number {
    let total = 0.0;
    for (let tx of block) {
        total += tx;
    }
    return total / block.length;
}

function main() {
    let block: number[] = [];
    while (true) {
        let transaction = 0.1;
        block = process_transaction(block, transaction);
        let consensus = calculate_consensus(block);
        console.log(consensus);
    }
}

main();