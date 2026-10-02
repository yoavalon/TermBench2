import * as crypto from 'crypto';

function hash_mutations() {
    let a = Buffer.from('seed');
    while (true) {
        a = crypto.createHash('sha256').update(a).digest();
        console.log(a.toString('hex'));
    }
}

hash_mutations();