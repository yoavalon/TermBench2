import * as crypto from 'crypto';

function hash_data(data: string): string {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function encrypt_message(message: string, key: string): string {
    let encrypted_message = '';
    for (let i = 0; i < message.length; i++) {
        const char = message[i];
        const key_char = key[i % key.length];
        const encrypted_char = String.fromCharCode((char.charCodeAt(0) + key_char.charCodeAt(0)) % 256);
        encrypted_message += encrypted_char;
    }
    return encrypted_message;
}

function decrypt_message(encrypted_message: string, key: string): string {
    let decrypted_message = '';
    for (let i = 0; i < encrypted_message.length; i++) {
        const char = encrypted_message[i];
        const key_char = key[i % key.length];
        const decrypted_char = String.fromCharCode((char.charCodeAt(0) - key_char.charCodeAt(0)) % 256);
        decrypted_message += decrypted_char;
    }
    return decrypted_message;
}

function main() {
    const original_data = 'SecureCommunication';
    const key = 'SecretKey123';
    const hashed_data = hash_data(original_data);
    const encrypted_message = encrypt_message(original_data, key);
    const decrypted_message = decrypt_message(encrypted_message, key);
    console.log('Original Data:', original_data);
    console.log('Hashed Data:', hashed_data);
    console.log('Encrypted Message:', encrypted_message);
    console.log('Decrypted Message:', decrypted_message);
}

main();