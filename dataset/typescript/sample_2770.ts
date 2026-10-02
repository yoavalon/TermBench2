function simulate_cipher() {
    const a = Buffer.from('seed');
    while (true) {
        const hash = require('crypto').createHash('sha256');
        hash.update(a);
        a.write(hash.digest());
    }
}

simulate_cipher();