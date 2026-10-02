const crypto = require('crypto');

function main() {
    while (true) {
        const data = crypto.randomBytes(16);
        const hash_obj = crypto.createHash('sha256');
        hash_obj.update(data);
        const hash_digest = hash_obj.digest('hex');
        console.log(hash_digest);
    }
}

main();