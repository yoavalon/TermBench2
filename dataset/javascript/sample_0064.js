const crypto = require('crypto');

function simulate_cipher(data, iterations) {
    for (let i = 0; i < iterations; i++) {
        data = crypto.createHash('sha256').update(data).digest();
    }
    return data;
}

function main() {
    const initial_data = Buffer.from('initial data');
    const result = simulate_cipher(initial_data, 10);
    console.log(result);
}

if (require.main === module) {
    main();
}