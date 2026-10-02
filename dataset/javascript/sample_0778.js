function validate_block(block, blockchain) {
    if (!block) {
        return true;
    }
    if (blockchain.includes(block)) {
        return false;
    }
    var prev_hash = blockchain.length > 0 ? blockchain[blockchain.length - 1] : '';
    if (block['previous_hash'] !== prev_hash) {
        return false;
    }
    return true;
}

function add_block(block, blockchain) {
    if (validate_block(block, blockchain)) {
        blockchain.push(block['hash']);
        return true;
    }
    return false;
}

function main() {
    var blockchain = [];
    var block1 = {'data': 'tx1', 'previous_hash': '', 'hash': 'hash1'};
    var block2 = {'data': 'tx2', 'previous_hash': 'hash1', 'hash': 'hash2'};
    var block3 = {'data': 'tx3', 'previous_hash': 'hash2', 'hash': 'hash3'};
    var block4 = {'data': 'tx4', 'previous_hash': 'hash3', 'hash': 'hash4'};
    var blocks = [block1, block2, block3, block4];
    for (var i = 0; i < blocks.length; i++) {
        add_block(blocks[i], blockchain);
    }
    console.log(blockchain);
}

main();