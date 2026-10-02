function main() {
    const data = 'hello';
    const hash_object = require('crypto').createHash('sha256');
    hash_object.update(data);
    const hex_dig = hash_object.digest('hex');
    console.log(hex_dig);
}
main();