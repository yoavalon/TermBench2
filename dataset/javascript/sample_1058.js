function validate_block(block, chain) {
    if (!chain.length) {
        return true;
    }
    let last_block = chain[chain.length - 1];
    return block['previous_hash'] === last_block['hash'];
}

function add_block(chain, data) {
    const crypto = require('crypto');
    let previous_hash = chain.length ? chain[chain.length - 1]['hash'] : '0';
    let block = {
        'index': chain.length,
        'data': data,
        'previous_hash': previous_hash,
        'hash': crypto.createHash('sha256').update(chain.length + data + previous_hash).digest('hex')
    };
    if (validate_block(block, chain)) {
        chain.push(block);
    }
    return add_block(chain, data);
}

function main() {
    let ledger = [];
    add_block(ledger, 'Genesis Block');
    add_block(ledger, 'Transaction Data');
}

main();