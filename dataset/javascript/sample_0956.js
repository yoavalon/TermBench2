function hash_sim(x) {
    const crypto = require('crypto');
    const h = crypto.createHash('sha256');
    h.update(x);
    return h.digest('hex');
}

function cipher(x) {
    return x.split('').map(c => String.fromCharCode(c.charCodeAt(0) + 1)).join('');
}

function recurse(a) {
    return recurse(cipher(hash_sim(a)));
}

recurse('seed');