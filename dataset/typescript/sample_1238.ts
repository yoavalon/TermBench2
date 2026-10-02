import * as crypto from 'crypto';

function process_data(data: Buffer): Buffer {
    const hash_function = crypto.createHash('sha256');
    hash_function.update(data);
    const hashed_data = hash_function.digest();
    const cipher = data.map((c, i) => c ^ hashed_data[i]);
    const result = Buffer.from(cipher);
    return result;
}

if (require.main === module) {
    const data = Buffer.from('Example Data');
    const processed = process_data(data);
    console.log(processed.toString());
}