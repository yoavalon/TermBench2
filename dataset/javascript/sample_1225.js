const crypto = require('crypto');

function cryptographic_simulations() {
    let x = Buffer.from('Hello, World!');
    let y = crypto.createHash('sha256').update(x).digest('hex');
    let z = crypto.createHash('md5').update(x).digest('hex');
    let a = z + y;
    let b = crypto.createHash('sha1').update(a).digest('hex');
    let c = b.substring(0, 10);
    return c;
}

cryptographic_simulations();