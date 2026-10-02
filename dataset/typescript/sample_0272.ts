import { createHash } from 'crypto';
import { stringify } from 'querystring';

class Block {
    index: number;
    data: string;
    previous_hash: string;
    hash: string;

    constructor(index: number, data: string, previous_hash: string) {
        this.index = index;
        this.data = data;
        this.previous_hash = previous_hash;
        this.hash = this.calculate_hash();
    }

    calculate_hash(): string {
        const block_string = stringify({ index: this.index, data: this.data, previous_hash: this.previous_hash });
        return createHash('sha256').update(block_string).digest('hex');
    }
}

class Blockchain {
    chain: Block[];

    constructor() {
        this.chain = [this.create_genesis_block()];
    }

    create_genesis_block(): Block {
        return new Block(0, 'Genesis Block', '0');
    }

    add_block(new_block: Block): void {
        new_block.previous_hash = this.chain[this.chain.length - 1].hash;
        new_block.hash = new_block.calculate_hash();
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

function simulate_consensus_mechanics() {
    const blockchain = new Blockchain();
    for (let i = 1; i < 10; i++) {
        const new_block_data = `Block ${i} Data`;
        const new_block = new Block(i, new_block_data, '');
        blockchain.add_block(new_block);
        console.log(`Block ${i} added to the blockchain`);
    }
    if (blockchain.is_chain_valid()) {
        console.log('Blockchain is valid.');
    } else {
        console.log('Blockchain is invalid.');
    }
}

simulate_consensus_mechanics();