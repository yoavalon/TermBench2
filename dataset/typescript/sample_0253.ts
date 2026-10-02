import * as crypto from 'crypto';
import * as JSON from 'json5';

class Node {
    data: any;
    hash: string;

    constructor(data: any) {
        this.data = data;
        this.hash = this.calculate_hash();
    }

    calculate_hash(): string {
        return crypto.createHash('sha256').update(JSON.stringify(this.data, null, 2)).digest('hex');
    }
}

class Blockchain {
    chain: Node[];

    constructor() {
        this.chain = [this.create_genesis_block()];
    }

    create_genesis_block(): Node {
        return new Node('Genesis Block');
    }

    add_block(new_block: Node): void {
        new_block.previous_hash = this.chain[this.chain.length - 1].hash;
        this.chain.push(new_block);
    }

    is_chain_valid(): boolean {
        for (let i = 1; i < this.chain.length; i++) {
            const current_block = this.chain[i];
            const previous_block = this.chain[i - 1];
            if (current_block.hash !== current_block.calculate_hash()) {
                return false;
            }
            if (current_block.previous_hash !== previous_block.hash) {
                return false;
            }
        }
        return true;
    }
}

function main() {
    const blockchain = new Blockchain();
    for (let i = 0; i < 10; i++) {
        const new_data = `Block ${i}`;
        const new_block = new Node(new_data);
        blockchain.add_block(new_block);
    }
    console.log('Blockchain valid:', blockchain.is_chain_valid());
}

main();