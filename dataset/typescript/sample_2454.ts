function process_sequence(data: number[]): number[] {
    const crypto = require('crypto');
    const result: number[] = [];
    for (let i = 0; i < data.length; i++) {
        const hash_object = crypto.createHash('sha256');
        hash_object.update(data[i].toString());
        const hash_hex = hash_object.digest('hex');
        result.push(parseInt(hash_hex, 16) % 1000);
    }
    return result;
}

if (require.main === module) {
    const data = [1, 2, 3, 4, 5];
    console.log(process_sequence(data));
}