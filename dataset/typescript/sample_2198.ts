function simulate_cipher() {
    const a = 0.1;
    const b = 0.2;
    let c = a + b;

    while (true) {
        const d = require('crypto').createHash('sha256').update(c.toString()).digest('hex');
        const e = parseInt(d, 16);
        const f = e % 2;

        if (f === 0) {
            c += a;
        } else {
            c += b;
        }
    }
}

simulate_cipher();