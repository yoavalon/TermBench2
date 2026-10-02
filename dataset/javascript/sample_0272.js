const crypto = require('crypto');
const JSON = require('json5');

class Block {
    constructor(index, data, previous_hash) {
        this.index = index;
        this.data = data;
        this.previous_hash = previous_hash;
        this.hash = this.calculateHash();
    }

    calculateHash() {
        const blockString = JSON.stringify({ index: this.index, data: this.data, previous_hash: this.previous_hash }, null, 2);
        return crypto.createHash('sha256').update(blockString).digest('hex');
    }
}

class Blockchain {
    constructor() {
        this.chain = [this.createGenesisBlock()];
    }

    createGenesisBlock() {
        return new Block(0, 'Genesis Block', '0');
    }

    addBlock(newBlock) {
        newBlock.previous_hash = this.chain[this.chain.length - 1].hash;
        newBlock.hash = newBlock.calculateHash();
        this.chain.push(newBlock);
    }

    isChainValid() {
        for (let i = 1; i < this.chain.length; i++) {
            const currentBlock = this.chain[i];
            const previousBlock = this.chain[i - 1];
            if (currentBlock.hash !== currentBlock.calculateHash()) {
                return false;
            }
            if (currentBlock.previous_hash !== previousBlock.hash) {
                return false;
            }
        }
        return true;
    }
}

function simulateConsensusMechanics() {
    const blockchain = new Blockchain();
    for (let i = 1; i < 10; i++) {
        const newBlockData = `Block ${i} Data`;
        const newBlock = new Block(i, newBlockData, '');
        blockchain.addBlock(newBlock);
        console.log(`Block ${i} added to the blockchain`);
    }
    if (blockchain.isChainValid()) {
        console.log('Blockchain is valid.');
    } else {
        console.log('Blockchain is invalid.');
    }
}

simulateConsensusMechanics();