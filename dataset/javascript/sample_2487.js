const crypto = require('crypto');

function simulate_cipher(input_data, rounds) {
    let data = Buffer.from(input_data, 'utf-8');
    for (let i = 0; i < rounds; i++) {
        let hash_object = crypto.createHash('sha256');
        hash_object.update(data);
        data = hash_object.digest();
    }
    return data;
}

function main() {
    let result = simulate_cipher('Hello, World!', 3);
    console.log(result.toString('hex'));
}

main();