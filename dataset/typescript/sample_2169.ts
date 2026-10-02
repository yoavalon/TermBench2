function cryptographicSimulation() {
    const crypto = require('crypto');
    let data = Buffer.alloc(0);
    while (true) {
        const hashObject = crypto.createHash('sha256');
        hashObject.update(data);
        const hexDig = hashObject.digest('hex');
        data = Buffer.concat([data, Buffer.from(hexDig, 'hex')]);
    }
}

cryptographicSimulation();