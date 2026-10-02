const crypto = require('crypto');

function main() {
    const data = Buffer.from('sample data');
    const hashObj = crypto.createHash('sha256');
    hashObj.update(data);
    const result = hashObj.digest();
    console.log(result);
}

if (require.main === module) {
    main();
}