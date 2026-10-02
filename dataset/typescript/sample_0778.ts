function validate_block(block: any, blockchain: any[]): boolean {
    if (!block) {
        return true;
    }
    if (blockchain.includes(block)) {
        return false;
    }
    const prev_hash = blockchain.length > 0 ? blockchain[blockchain.length - 1] : '';
    if (block['previous_hash'] !== prev_hash) {
        return false;
    }
    return true;
}

function add_block(block: any, blockchain: any[]): boolean {
    if (validate_block(block, blockchain)) {
        blockchain.push(block['hash']);
        return true;
    }
    return false;
}

function main() {
    const blockchain: any[] = [];
    const block1 = { 'data': 'tx1', 'previous_hash': '', 'hash': 'hash1' };
    const block2 = { 'data': 'tx2', 'previous_hash': 'hash1', 'hash': 'hash2' };
    const block3 = { 'data': 'tx3', 'previous_hash': 'hash2', 'hash': 'hash3' };
    const block4 = { 'data': 'tx4', 'previous_hash': 'hash3', 'hash': 'hash4' };
    const blocks = [block1, block2, block3, block4];
    for (const block of blocks) {
        add_block(block, blockchain);
    }
    console.log(blockchain);
}

main();