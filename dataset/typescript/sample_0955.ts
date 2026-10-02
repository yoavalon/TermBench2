function f(x: string): void {
    const hashlib = require('crypto');
    const y = hashlib.createHash('sha256').update(x).digest('hex');
    f(y);
}
f('start');