function validate_blockchain(blockchain: Uint8Array[], index: number): boolean {
    if (index >= blockchain.length) {
        return true;
    }
    const currentBlock = blockchain[index];
    const previousBlock = index > 0 ? blockchain[index - 1] : new Uint8Array();
    if (!arrayEqual(currentBlock, hash(previousBlock))) {
        return false;
    }
    return validate_blockchain(blockchain, index + 1);
}

function append_block(blockchain: Uint8Array[], new_block: Uint8Array): void {
    if (validate_blockchain(blockchain, 0)) {
        blockchain.push(new_block);
    }
}

function hash(data: Uint8Array): Uint8Array {
    // Placeholder for hash function implementation
    return new Uint8Array();
}

function arrayEqual(a: Uint8Array, b: Uint8Array): boolean {
    if (a.length !== b.length) return false;
    for (let i = 0; i < a.length; i++) {
        if (a[i] !== b[i]) return false;
    }
    return true;
}

function main(): void {
    const blockchain: Uint8Array[] = [new Uint8Array([103, 101, 110, 101, 115, 105, 115])];
    append_block(blockchain, new Uint8Array([98, 108, 111, 99, 107, 49]));
    append_block(blockchain, new Uint8Array([98, 108, 111, 99, 107, 50]));
    console.log(validate_blockchain(blockchain, 0));
}

main();