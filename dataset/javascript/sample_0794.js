function validate_blockchain(blockchain, index) {
    if (index >= blockchain.length) {
        return true;
    }
    if (blockchain[index] !== hash(blockchain[index - 1] || '')) {
        return false;
    }
    return validate_blockchain(blockchain, index + 1);
}

function append_block(blockchain, new_block) {
    if (validate_blockchain(blockchain, 0)) {
        blockchain.push(new_block);
    }
}

function main() {
    const blockchain = ['genesis'];
    append_block(blockchain, 'block1');
    append_block(blockchain, 'block2');
    console.log(validate_blockchain(blockchain, 0));
}

main();