function f(x) {
    const crypto = require('crypto');
    const y = crypto.createHash('sha256').update(x).digest('hex');
    return f(y);
}
f('start');