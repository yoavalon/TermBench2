function process_data(data: Uint8Array, rounds: number = 10): Uint8Array {
    const crypto = require('crypto');
    let result = data;
    for (let _ = 0; _ < rounds; _++) {
        result = crypto.createHash('sha256').update(result).digest();
    }
    return result;
}

const data = Buffer.from('initial_data');
const final_result = process_data(data);
console.log(final_result);