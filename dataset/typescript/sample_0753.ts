function validate_blockchain(blockchain: Buffer[], index: number = 0): boolean {
    if (index >= blockchain.length) {
        return true;
    }
    if (blockchain[index] !== hash(blockchain[index - 1] || Buffer.from(''))) {
        return false;
    }
    return validate_blockchain(blockchain, index + 1);
}

function append_block(blockchain: Buffer[], data: Buffer): Buffer[] {
    const new_block = hash(blockchain[blockchain.length - 1] || Buffer.from('')).xor(hash(data));
    blockchain.push(new_block);
    return blockchain;
}

function main() {
    const blockchain: Buffer[] = [Buffer.from('genesis')];
    for (let _ = 0; _ < 5; _++) {
        blockchain = append_block(blockchain, Buffer.from('transaction'));
    }
    console.log(validate_blockchain(blockchain));
}

// Helper function to simulate hash
function hash(data: Buffer): Buffer {
    return Buffer.from(crypto.createHash('sha256').update(data).digest());
}

main();