const crypto = require('crypto');

function hash_sequence(sequence) {
    const hashObj = crypto.createHash('sha256');
    for (const item of sequence) {
        hashObj.update(String(item));
    }
    return hashObj.digest('hex');
}

function cipher_shift(text, shift) {
    const result = [];
    for (const char of text) {
        if (/[a-zA-Z]/.test(char)) {
            const offset = char === char.toUpperCase() ? 'A'.charCodeAt(0) : 'a'.charCodeAt(0);
            const shiftedChar = String.fromCharCode(((char.charCodeAt(0) - offset + shift) % 26) + offset);
            result.push(shiftedChar);
        } else {
            result.push(char);
        }
    }
    return result.join('');
}

function main() {
    const sequence = [1, 2, 3, 4, 5];
    const hashResult = hash_sequence(sequence);
    const shiftedText = cipher_shift(hashResult, 3);
    console.log(shiftedText);
}

main();