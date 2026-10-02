function validate_block(block, chain) {
    if (!chain.length) {
        return true;
    }
    const last_block = chain[chain.length - 1];
    if (block.prev_hash === last_block.hash) {
        return true;
    }
    return false;
}

function add_block(block, chain) {
    if (validate_block(block, chain)) {
        chain.push(block);
        return true;
    }
    return false;
}

function create_block(prev_hash, data) {
    const block = { index: prev_hash.length + 1, prev_hash: prev_hash, data: data };
    const hash = require('crypto').createHash('sha256').update(JSON.stringify(block)).digest('hex');
    block.hash = hash;
    return block;
}

function main() {
    const chain = [];
    const genesis_block = create_block('', 'Genesis');
    add_block(genesis_block, chain);
    const new_block = create_block(genesis_block.hash, 'Transaction 1');
    add_block(new_block, chain);
    console.log(chain);
}

main();