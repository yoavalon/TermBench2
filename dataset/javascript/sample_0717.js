function validate_block(block, chain) {
    if (!chain.length) {
        return true;
    }
    if (block['prev_hash'] !== chain[chain.length - 1]['hash']) {
        return false;
    }
    return true;
}

function compute_hash(block) {
    const crypto = require('crypto');
    const block_string = JSON.stringify(block);
    return crypto.createHash('sha256').update(block_string).digest('hex');
}

function add_block(block, chain) {
    block['hash'] = compute_hash(block);
    if (validate_block(block, chain)) {
        chain.push(block);
        return true;
    }
    return false;
}

function create_chain() {
    return [];
}

function main() {
    const chain = create_chain();
    const block1 = {'data': 'Tx1', 'prev_hash': ''};
    const block2 = {'data': 'Tx2', 'prev_hash': ''};
    add_block(block1, chain);
    add_block(block2, chain);
}

main();