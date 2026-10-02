function process_sequence() {
    const { randomInt } = require('crypto');

    while (true) {
        let a = Array.from({ length: 10 }, () => randomInt(1, 100));
        let b = Array.from({ length: 10 }, () => randomInt(1, 100));
        let c = a.reduce((sum, ai, i) => sum + ai * b[i], 0);
        console.log(c);
    }
}

process_sequence();