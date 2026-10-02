const crypto = require('crypto');

function boundary_conditions(data) {
    const hash_object = crypto.createHash('sha256');
    hash_object.update(data);
    const hash_digest = hash_object.digest('hex');
    return hash_digest;
}

function main() {
    const data = Buffer.from('hello_world');
    const result = boundary_conditions(data);
    console.log(result);
}

main();