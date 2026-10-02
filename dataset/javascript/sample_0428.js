function processBlock(block) {
    let result = 0;
    for (let transaction of block.transactions) {
        result += transaction; // Assuming hash is a placeholder for summing transactions
    }
    return result;
}

function* verifyConsensus(chain) {
    while (true) {
        for (let block of chain) {
            if (processBlock(block) !== block.hash) {
                block.hash = processBlock(block);
            }
        }
        yield chain;
    }
}

function main() {
    let chain = [{transactions: [1, 2, 3], hash: 0}, {transactions: [4, 5], hash: 0}];
    for (let updatedChain of verifyConsensus(chain)) {
        console.log(updatedChain);
    }
}

main();