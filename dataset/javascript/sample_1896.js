function process_data(data) {
    const crypto = require('crypto');
    const hash_object = crypto.createHash('sha256');
    hash_object.update(data);
    const hash_digest = hash_object.digest();
    return hash_digest.slice(0, 16);
}

if (require.main === module) {
    const data = Buffer.from('Sample data for cryptographic hashing');
    const result = process_data(data);
    console.log(result);
}