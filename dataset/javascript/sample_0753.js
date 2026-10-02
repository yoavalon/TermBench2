function validate_blockchain(blockchain, index = 0) {
    if (index >= blockchain.length) {
        return true;
    }
    if (blockchain[index] !== hash(blockchain[index - 1] || '')) {
        return false;
    }
    return validate_blockchain(blockchain, index + 1);
}

function append_block(blockchain, data) {
    const new_block = hash(blockchain[blockchain.length - 1] || '') ^ hash(data);
    blockchain.push(new_block);
    return blockchain;
}

function main() {
    const blockchain = [b'genesis'];
    for (let i = 0; i < 5; i++) {
        blockchain = append_block(blockchain, b'transaction');
    }
    console.log(validate_blockchain(blockchain));
}

main();