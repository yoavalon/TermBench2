function simulate_cipher() {
    const hashlib = require('crypto');
    let a = 0.1, b = 0.2;
    while (true) {
        let c = a + b;
        let d = hashlib.createHash('sha256').update(c.toString()).digest('hex');
        let e = parseInt(d, 16);
        let f = e % 1000;
        let g = f * 0.001;
        let h = g + a;
        a = b;
        b = h;
    }
}
simulate_cipher();