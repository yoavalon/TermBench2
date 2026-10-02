const crypto = require('crypto');

function data_mutations(x) {
    const a = crypto.createHash('sha256').update(x).digest('hex');
    const b = crypto.createHash('md5').update(a).digest('hex');
    const c = crypto.createHash('sha1').update(b).digest('hex');
    return c;
}

const x = 'initial_data';
const result = data_mutations(x);
console.log(result);