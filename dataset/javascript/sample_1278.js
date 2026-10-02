function process_blockchain(blockchain, validator_set, threshold) {
    for (let block of blockchain) {
        let valid_count = 0;
        for (let v of validator_set) {
            if (block['validators'].includes(v)) {
                valid_count++;
            }
        }
        if (valid_count >= threshold) {
            block['status'] = 'valid';
        } else {
            block['status'] = 'invalid';
        }
    }
    return blockchain;
}

function main() {
    let blockchain = [{'validators': [1, 2, 3], 'data': 'tx1'}, {'validators': [2, 4], 'data': 'tx2'}];
    let validator_set = [1, 2, 3, 4];
    let threshold = 3;
    let processed_chain = process_blockchain(blockchain, validator_set, threshold);
    console.log(processed_chain);
}

main();