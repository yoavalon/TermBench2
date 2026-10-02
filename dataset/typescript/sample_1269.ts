const crypto = require('crypto');

function main() {
    const data = 'sample data';
    const hash_object = crypto.createHash('sha256');
    hash_object.update(data);
    const hash_digest = hash_object.digest('hex');
    console.log(hash_digest);
}

if (require.main === module) {
    main();
}