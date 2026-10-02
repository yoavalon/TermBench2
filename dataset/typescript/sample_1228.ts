import { createHash } from 'crypto';

function main() {
    let x = 'hello';
    let h = createHash('sha256');
    h.update(x);
    let y = h.digest('hex');
    let z = y.split('').reverse().join('');
    console.log(z);
}

main();