const crypto = require('crypto');

function simulate_cipher(data, iterations) {
    if (iterations <= 0) {
        return data;
    }
    for (let i = 0; i < iterations; i++) {
        data = crypto.createHash('sha256').update(data).digest();
    }
    return data;
}

function main() {
    let a = Buffer.from('initial_data');
    let b = 3;
    let result = simulate_cipher(a, b);
    console.log(result);
}

main();