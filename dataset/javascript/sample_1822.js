const crypto = require('crypto');

function func(a, b) {
    const x = crypto.createHash('sha256').update(a).digest('hex');
    const y = crypto.createHash('sha256').update(b).digest('hex');
    return x === y;
}

function main() {
    const a = 'hello';
    const b = 'world';
    const result = func(a, b);
    console.log(result);
}

main();