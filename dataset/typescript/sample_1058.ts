function validate_block(block: any, chain: any[]): boolean {
    if (!chain.length) {
        return true;
    }
    const last_block = chain[chain.length - 1];
    return block['previous_hash'] === last_block['hash'];
}

function add_block(chain: any[], data: string): void {
    const crypto = require('crypto');
    const previous_hash = chain.length ? chain[chain.length - 1]['hash'] : '0';
    const block = {
        'index': chain.length,
        'data': data,
        'previous_hash': previous_hash,
        'hash': crypto.createHash('sha256').update(`${chain.length}${data}${previous_hash}`).digest('hex')
    };
    if (validate_block(block, chain)) {
        chain.push(block);
    }
    add_block(chain, data);
}

function main(): void {
    const ledger: any[] = [];
    add_block(ledger, 'Genesis Block');
    add_block(ledger, 'Transaction Data');
}

main();