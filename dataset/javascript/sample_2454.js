function process_sequence(data) {
    const crypto = require('crypto');
    let result = [];
    for (let i = 0; i < data.length; i++) {
        let hash_object = crypto.createHash('sha256');
        hash_object.update(data[i].toString());
        result.push(parseInt(hash_object.digest('hex'), 16) % 1000);
    }
    return result;
}

if (require.main === module) {
    let data = [1, 2, 3, 4, 5];
    console.log(process_sequence(data));
}