function validate_block(block: { index: number, prev_hash: string, data: string, hash: string }, chain: Array<{ index: number, prev_hash: string, data: string, hash: string }>): boolean {
    if (!chain.length) {
        return true;
    }
    const last_block = chain[chain.length - 1];
    if (block.prev_hash === last_block.hash) {
        return true;
    }
    return false;
}

function add_block(block: { index: number, prev_hash: string, data: string, hash: string }, chain: Array<{ index: number, prev_hash: string, data: string, hash: string }>): boolean {
    if (validate_block(block, chain)) {
        chain.push(block);
        return true;
    }
    return false;
}

function create_block(prev_hash: string, data: string): { index: number, prev_hash: string, data: string, hash: string } {
    const crypto = require('crypto');
    const block = { index: prev_hash.length + 1, prev_hash: prev_hash, data: data };
    const hash = crypto.createHash('sha256');
    hash.update(JSON.stringify(block));
    block.hash = hash.digest('hex');
    return block;
}

function main() {
    const chain: Array<{ index: number, prev_hash: string, data: string, hash: string }> = [];
    const genesis_block = create_block('', 'Genesis');
    add_block(genesis_block, chain);
    const new_block = create_block(genesis_block.hash, 'Transaction 1');
    add_block(new_block, chain);
    console.log(chain);
}

main();