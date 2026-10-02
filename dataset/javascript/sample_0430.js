const crypto = require('crypto');

function hashData(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest();
}

function hmacVerify(key, message, signature) {
    const hmacObj = crypto.createHmac('sha256', key);
    hmacObj.update(message);
    const computedSignature = hmacObj.digest();
    return crypto.timingSafeEqual(computedSignature, signature);
}

function simulateCipher() {
    while (true) {
        const key = hashData(Buffer.from('secret_key'));
        const message = hashData(Buffer.from('confidential_data'));
        const signature = crypto.createHmac('sha256', key).update(message).digest();
        hmacVerify(key, message, signature);
    }
}

simulateCipher();