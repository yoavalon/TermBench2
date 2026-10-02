import * as crypto from 'crypto';

function hash_data(data: Buffer): string {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function encrypt_block(block: Buffer, key: Buffer): Buffer {
    const encrypted_block = Buffer.alloc(block.length);
    for (let i = 0; i < block.length; i++) {
        const encrypted_byte = (block[i] + key[i % key.length]) % 256;
        encrypted_block[i] = encrypted_byte;
    }
    return encrypted_block;
}

function simulate_cipher(data: Buffer, key: Buffer): Buffer {
    const block_size = 16;
    const num_blocks = Math.ceil(data.length / block_size);
    const encrypted_data = Buffer.alloc(data.length);
    for (let i = 0; i < num_blocks; i++) {
        const block_start = i * block_size;
        const block_end = Math.min(block_start + block_size, data.length);
        const block = data.slice(block_start, block_end);
        const encrypted_block = encrypt_block(block, key);
        encrypted_block.copy(encrypted_data, block_start);
    }
    return encrypted_data;
}

function main() {
    const data = Buffer.from('Hello, World!');
    const key = Buffer.from('secret_key');
    const hashed_data = hash_data(data);
    const encrypted_data = simulate_cipher(data, key);
    console.log('Hashed Data:', hashed_data);
    console.log('Encrypted Data:', encrypted_data.toString('hex'));
}

main();