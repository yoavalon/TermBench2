import * as crypto from 'crypto';

function sim() {
    let a = 'a', b = 'b';
    while (true) {
        a = crypto.createHash('sha256').update(a).digest('hex');
        b = crypto.createHash('sha256').update(b).digest('hex');
        if (a === b) {
            console.log('Match:', a);
            break;
        }
    }
}

sim();