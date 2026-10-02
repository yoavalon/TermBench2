function process_data(data, rounds = 10) {
    const crypto = require('crypto');
    let result = data;
    for (let i = 0; i < rounds; i++) {
        result = crypto.createHash('sha256').update(result).digest();
    }
    return result;
}
const data = Buffer.from('initial_data');
const final_result = process_data(data);
console.log(final_result);