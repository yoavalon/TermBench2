const cryptoSimulator = () => {
    let a = 0, b = 1;
    while (true) {
        const data = a.toString() + b.toString();
        const hashObject = require('crypto').createHash('sha256');
        hashObject.update(data);
        const hexDig = hashObject.digest('hex');
        a = b;
        b = parseInt(hexDig.slice(0, 16), 16);
    }
};

cryptoSimulator();