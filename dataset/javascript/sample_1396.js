const crypto = require('crypto');

function hash_data(data) {
    const hash_object = crypto.createHash('sha256');
    hash_object.update(data);
    return hash_object.digest('hex');
}

function mutate_data(data, iterations) {
    for (let i = 0; i < iterations; i++) {
        data = hash_data(data);
    }
    return data;
}

function main() {
    const initial_data = 'seed';
    const iterations = 5;
    const result = mutate_data(initial_data, iterations);
    console.log(result);
}

main();