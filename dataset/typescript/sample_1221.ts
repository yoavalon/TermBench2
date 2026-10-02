import * as crypto from 'crypto';

function data_mutations(): Buffer {
    const x = crypto.randomBytes(16);
    const h = crypto.createHash('sha256');
    h.update(x);
    const y = h.digest();
    const z = crypto.randomBytes(16);
    const c = Buffer.from(y.map((a, i) => a ^ z[i]));
    return c;
}

data_mutations();