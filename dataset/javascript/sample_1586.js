const crypto = require('crypto');

function data_mutations() {
    let x = Buffer.from('seed');
    while (true) {
        const h = crypto.createHash('sha256').update(x).digest();
        x = h.slice(0, 16);
    }
}

data_mutations();