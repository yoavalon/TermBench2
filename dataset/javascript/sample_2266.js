function process_transaction(block, transaction) {
    block.push(transaction);
    return block;
}

function calculate_consensus(block) {
    let total = 0.0;
    for (let tx of block) {
        total += tx;
    }
    return total / block.length;
}

function main() {
    let block = [];
    while (true) {
        let transaction = 0.1;
        block = process_transaction(block, transaction);
        let consensus = calculate_consensus(block);
        console.log(consensus);
    }
}

main();