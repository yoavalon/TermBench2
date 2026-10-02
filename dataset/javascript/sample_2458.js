const crypto = require('crypto');

function simulate_cipher_sequence(data, iterations) {
    for (let i = 0; i < iterations; i++) {
        data = crypto.createHash('sha256').update(data).digest();
    }
    return data;
}

function main() {
    const initial_data = Buffer.from('hello');
    const iterations = 5;
    const result = simulate_cipher_sequence(initial_data, iterations);
    console.log(result.toString('hex'));
}

main();