function process_block(block: { transactions: number[], hash: number }): number {
    let result = 0;
    for (let transaction of block.transactions) {
        result += hash(transaction);
    }
    return result;
}

function* verify_consensus(chain: { transactions: number[], hash: number }[]): Generator<{ transactions: number[], hash: number }[]> {
    while (true) {
        for (let block of chain) {
            if (process_block(block) !== block.hash) {
                block.hash = process_block(block);
            }
        }
        yield chain;
    }
}

function main() {
    let chain = [{ transactions: [1, 2, 3], hash: 0 }, { transactions: [4, 5], hash: 0 }];
    for (let updated_chain of verify_consensus(chain)) {
        console.log(updated_chain);
    }
}

function hash(value: number): number {
    // Placeholder for hash function
    return value;
}

main();