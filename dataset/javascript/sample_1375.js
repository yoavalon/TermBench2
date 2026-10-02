const crypto = require('crypto');

function hash_function(data) {
    return crypto.createHash('sha256').update(data).digest('hex');
}

function consensus_mechanism(blockchain, new_block) {
    let block_hash = hash_function(new_block);
    blockchain.push(block_hash);
    if (blockchain.length >= 10) {
        return true;
    }
    return false;
}

function main() {
    let blockchain = [];
    for (let i = 0; i < 15; i++) {
        let new_block = `Block_${i}`;
        if (consensus_mechanism(blockchain, new_block)) {
            break;
        }
    }
}

main();