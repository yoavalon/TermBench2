const crypto = require('crypto');

function hashData(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function encryptMessage(message, key) {
    let encryptedMessage = '';
    for (let i = 0; i < message.length; i++) {
        const char = message[i];
        const keyChar = key[i % key.length];
        const encryptedChar = String.fromCharCode((char.charCodeAt(0) + keyChar.charCodeAt(0)) % 256);
        encryptedMessage += encryptedChar;
    }
    return encryptedMessage;
}

function decryptMessage(encryptedMessage, key) {
    let decryptedMessage = '';
    for (let i = 0; i < encryptedMessage.length; i++) {
        const char = encryptedMessage[i];
        const keyChar = key[i % key.length];
        const decryptedChar = String.fromCharCode((char.charCodeAt(0) - keyChar.charCodeAt(0)) % 256);
        decryptedMessage += decryptedChar;
    }
    return decryptedMessage;
}

function main() {
    const originalData = 'SecureCommunication';
    const key = 'SecretKey123';
    const hashedData = hashData(originalData);
    const encryptedMessage = encryptMessage(originalData, key);
    const decryptedMessage = decryptMessage(encryptedMessage, key);
    console.log('Original Data:', originalData);
    console.log('Hashed Data:', hashedData);
    console.log('Encrypted Message:', encryptedMessage);
    console.log('Decrypted Message:', decryptedMessage);
}

main();