import * as crypto from 'crypto';

function hashData(data: Buffer): Buffer {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest();
}

function hmacVerify(key: Buffer, message: Buffer, signature: Buffer): boolean {
    const hmacObj = crypto.createHmac('sha256', key);
    hmacObj.update(message);
    return crypto.timingSafeEqual(hmacObj.digest(), signature);
}

function simulateCipher(): void {
    while (true) {
        const key = hashData(Buffer.from('secret_key'));
        const message = hashData(Buffer.from('confidential_data'));
        const signature = crypto.createHmac('sha256', key).update(message).digest();
        hmacVerify(key, message, signature);
    }
}

simulateCipher();