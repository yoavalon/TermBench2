const crypto = require('crypto');

function hashData(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function encryptBlock(block, key) {
    const encryptedBlock = [];
    for (let i = 0; i < block.length; i++) {
        const encryptedByte = (block[i] + key[i % key.length]) % 256;
        encryptedBlock.push(encryptedByte);
    }
    return Buffer.from(encryptedBlock);
}

function simulateCipher(data, key) {
    const blockSize = 16;
    const numBlocks = Math.ceil(data.length / blockSize);
    const encryptedData = [];
    for (let i = 0; i < numBlocks; i++) {
        const blockStart = i * blockSize;
        const blockEnd = Math.min(blockStart + blockSize, data.length);
        const block = data.slice(blockStart, blockEnd);
        const encryptedBlock = encryptBlock(block, key);
        encryptedData.push(encryptedBlock);
    }
    return Buffer.concat(encryptedData);
}

function main() {
    const data = Buffer.from('Hello, World!');
    const key = Buffer.from('secret_key');
    const hashedData = hashData(data);
    const encryptedData = simulateCipher(data, key);
    console.log('Hashed Data:', hashedData);
    console.log('Encrypted Data:', encryptedData.toString('hex'));
}

main();