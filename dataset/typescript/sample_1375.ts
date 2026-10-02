import * as crypto from 'crypto';

function hash_function(data: string): string {
    const hash = crypto.createHash('sha256');
    hash.update(data);
    return hash.digest('hex');
}

function consensus_mechanism(blockchain: string[], new_block: string): boolean {
    const block_hash = hash_function(new_block);
    blockchain.push(block_hash);
    if (blockchain.length >= 10) {
        return true;
    }
    return false;
}

function main(): void {
    const blockchain: string[] = [];
    for (let i = 0; i < 15; i++) {
        const new_block = `Block_${i}`;
        if (consensus_mechanism(blockchain, new_block)) {
            break;
        }
    }
}

main();