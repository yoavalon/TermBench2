import * as crypto from 'crypto';

function hash_sequence(sequence: any[]): string {
    const hashObj = crypto.createHash('sha256');
    for (const item of sequence) {
        hashObj.update(String(item));
    }
    return hashObj.digest('hex');
}

function cipher_shift(text: string, shift: number): string {
    let result = '';
    for (const char of text) {
        if (char >= 'A' && char <= 'Z' || char >= 'a' && char <= 'z') {
            const offset = char === char.toUpperCase() ? 'A'.charCodeAt(0) : 'a'.charCodeAt(0);
            const shiftedChar = String.fromCharCode(((char.charCodeAt(0) - offset + shift) % 26) + offset);
            result += shiftedChar;
        } else {
            result += char;
        }
    }
    return result;
}

function main() {
    const sequence = [1, 2, 3, 4, 5];
    const hashResult = hash_sequence(sequence);
    const shiftedText = cipher_shift(hashResult, 3);
    console.log(shiftedText);
}

main();