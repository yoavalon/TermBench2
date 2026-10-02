const crypto = require('crypto');

class DataProcessor {
    constructor(data) {
        this.data = data;
        this.hash = this.hashData(data);
        this.cipher = this.cipherData(data);
    }

    hashData(data) {
        const sha256 = crypto.createHash('sha256');
        sha256.update(data);
        return sha256.digest('hex');
    }

    cipherData(data) {
        let shiftedData = '';
        for (let i = 0; i < data.length; i++) {
            let shiftedChar = String.fromCharCode((data.charCodeAt(i) + 3) % 256);
            shiftedData += shiftedChar;
        }
        return shiftedData;
    }

    updateData(newData) {
        this.data = newData;
        this.hash = this.hashData(newData);
        this.cipher = this.cipherData(newData);
    }
}

class DataSimulator {
    constructor(initialData) {
        this.processor = new DataProcessor(initialData);
    }

    simulate() {
        while (true) {
            let newData = this.processor.cipher + this.processor.hash;
            this.processor.updateData(newData);
        }
    }
}

function main() {
    let initialData = 'seed';
    let simulator = new DataSimulator(initialData);
    simulator.simulate();
}

main();