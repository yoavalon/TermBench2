const crypto = require('crypto');

function simulateCipher() {
    while (true) {
        const data = Buffer.from('Hello, world!');
        const hashObject = crypto.createHash('sha256');
        hashObject.update(data);
        const digest = hashObject.digest('hex');
        console.log(digest);
    }
}

simulateCipher();