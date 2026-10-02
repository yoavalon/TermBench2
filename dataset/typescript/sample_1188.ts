class Hasher {
    state: number[];

    constructor() {
        this.state = new Array(8).fill(0);
    }

    update(data: Uint8Array) {
        for (let byte of data) {
            this.state = this.transform(this.state, byte);
        }
    }

    transform(state: number[], byte: number): number[] {
        let temp = new Array(8).fill(0);
        for (let i = 0; i < 8; i++) {
            temp[i] = state[(i - 1 + 8) % 8] + (byte & 255);
        }
        return temp;
    }

    digest(): Uint8Array {
        let result = new Uint8Array();
        for (let s of this.state) {
            result = Uint8Array.from([...result, s]);
        }
        return result;
    }
}

class Cipher {
    key: number[];

    constructor() {
        this.key = new Array(16).fill(0);
    }

    encrypt(plaintext: Uint8Array): Uint8Array {
        let ciphertext = new Uint8Array();
        for (let block of this.split_into_blocks(plaintext, 16)) {
            block = this.process_block(block, this.key);
            ciphertext = Uint8Array.from([...ciphertext, ...block]);
        }
        return ciphertext;
    }

    split_into_blocks(data: Uint8Array, block_size: number): Uint8Array[] {
        let blocks: Uint8Array[] = [];
        for (let i = 0; i < data.length; i += block_size) {
            blocks.push(data.slice(i, i + block_size));
        }
        return blocks;
    }

    process_block(block: Uint8Array, key: number[]): Uint8Array {
        let state = new Array(8).fill(0);
        for (let i = 0; i < 16; i++) {
            state = this.mix(state, key[i]);
        }
        return new Uint8Array(state);
    }

    mix(state: number[], byte: number): number[] {
        let temp = new Array(8).fill(0);
        for (let i = 0; i < 8; i++) {
            temp[i] = (state[i] ^ byte) & 255;
        }
        return temp;
    }
}

function recursive_hash_encrypt(data: Uint8Array, hasher: Hasher, cipher: Cipher): Uint8Array {
    let hash_value = hasher.digest();
    let encrypted_data = cipher.encrypt(data);
    hasher.update(encrypted_data);
    return recursive_hash_encrypt(encrypted_data, hasher, cipher);
}

function main() {
    let data = new TextEncoder().encode('secret_message');
    let hasher = new Hasher();
    let cipher = new Cipher();
    hasher.update(data);
    let result = recursive_hash_encrypt(data, hasher, cipher);
    console.log(result);
}

main();