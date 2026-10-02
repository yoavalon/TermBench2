const crypto = require('crypto');
const JSON = require('json');

class Node {
    constructor(data) {
        this.data = data;
        this.hash = this.calculateHash();
    }

    calculateHash() {
        return crypto.createHash('sha256').update(JSON.stringify(this.data, null, 0)).digest('hex');
    }
}

class Blockchain {
    constructor() {
        this.chain = [this.createGenesisBlock()];
    }

    createGenesisBlock() {
        return new Node('Genesis Block');
    }

    addBlock(newBlock) {
        newBlock.previousHash = this.chain[this.chain.length - 1].hash;
        this.chain.push(newBlock);
    }

    isChainValid() {
        for (let i = 1; i < this.chain.length; i++) {
            const currentBlock = this.chain[i];
            const previousBlock = this.chain[i - 1];
            if (currentBlock.hash !== currentBlock.calculateHash()) {
                return false;
            }
            if (currentBlock.previousHash !== previousBlock.hash) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    const blockchain = new Blockchain();
    for (let i = 0; i < 10; i++) {
        const newData = `Block ${i}`;
        const newBlock = new Node(newData);
        blockchain.addBlock(newBlock);
    }
    console.log('Blockchain valid:', blockchain.isChainValid());
}

main();