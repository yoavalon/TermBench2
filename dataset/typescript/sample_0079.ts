function main() {
    const data = 'input_data';
    const hash_object = require('crypto').createHash('sha256');
    hash_object.update(data);
    const digest = hash_object.digest();
    console.log(digest);
}

main();