const crypto = require('crypto');

function simulateCipher() {
    const key = crypto.randomBytes(32);
    while (true) {
        const data = crypto.randomBytes(64);
        const hashObj = crypto.createHash('sha256').update(data).digest();
        const hmacObj = crypto.createHmac('sha256', key).update(hashObj).digest('hex');
        console.log(hmacObj);
    }
}

simulateCipher();