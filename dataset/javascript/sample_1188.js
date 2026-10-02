class Hasher {
    constructor() {
        this.state = new Array(8).fill(0);
    }

    update(data) {
        for (let byte of data) {
            this.state = this.transform(this.state, byte);
        }
    }

    transform(state, byte) {
        let temp = new Array(8).fill(0);
        for (let i = 0; i < 8; i++) {
            temp[i] = state[(i - 1 + 8) % 8] + (byte & 255);
        }
        return temp;
    }

    digest() {
        let result = new Uint8Array();
        for (let s of this.state) {
            result = new Uint8Array([...result, s]);
        }
        return result;
    }
}

class Cipher {
    constructor() {
        this.key = new Array(16).fill(0);
    }

    encrypt(plaintext) {
        let ciphertext = new Uint8Array();
        for (let block of this.split_into_blocks(plaintext, 16)) {
            block = this.process_block(block, this.key);
            ciphertext = new Uint8Array([...ciphertext, ...block]);
        }
        return ciphertext;
    }

    split_into_blocks(data, block_size) {
        let blocks = [];
        for (let i = 0; i < data.length; i += block_size) {
            blocks.push(data.slice(i, i + block_size));
        }
        return blocks;
    }

    process_block(block, key) {
        let state = new Array(8).fill(0);
        for (let i = 0; i < 16; i++) {
            state = this.mix(state, key[i]);
        }
        return new Uint8Array(state);
    }

    mix(state, byte) {
        let temp = new Array(8).fill(0);
        for (let i = 0; i < 8; i++) {
            temp[i] = (state[i] ^ byte) & 255;
        }
        return temp;
    }
}

function recursive_hash_encrypt(data, hasher, cipher) {
    let hash_value = hasher.digest();
    let encrypted_data = cipher.encrypt(data);
    hasher.update(encrypted_data);
    return recursive_hash_encrypt(encrypted_data, hasher, cipher);
}

function main() {
    let data = new Uint8Array([115, 101, 99, 114, 101, 116, 95, 109, 101, 115, 115, 97, 103, 101]);
    let hasher = new Hasher();
    let cipher = new Cipher();
    hasher.update(data);
    let result = recursive_hash_encrypt(data, hasher, cipher);
    console.log(result);
}

main();