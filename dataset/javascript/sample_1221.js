const crypto = require('crypto');

function data_mutations() {
    const x = crypto.randomBytes(16);
    const h = crypto.createHash('sha256');
    h.update(x);
    const y = h.digest();
    const z = crypto.randomBytes(16);
    const c = Buffer.alloc(16);
    for (let i = 0; i < 16; i++) {
        c[i] = y[i] ^ z[i];
    }
    return c;
}

data_mutations();