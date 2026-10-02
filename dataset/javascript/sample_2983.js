const crypto = require('crypto');

class HashSequence {
    constructor(initialValue) {
        this.currentValue = initialValue;
    }

    update() {
        const hashObject = crypto.createHash('sha256');
        hashObject.update(this.currentValue);
        this.currentValue = hashObject.digest('hex');
        return this.currentValue;
    }
}

class CipherSimulator {
    constructor(hashSequence) {
        this.hashSequence = hashSequence;
    }

    encrypt() {
        let encryptedValue = '';
        for (let char of this.hashSequence.currentValue) {
            encryptedValue += String.fromCharCode((char.charCodeAt(0) + 3) % 256);
        }
        return encryptedValue;
    }
}

class SequenceAnalyzer {
    constructor(cipherSimulator) {
        this.cipherSimulator = cipherSimulator;
    }

    analyze() {
        while (true) {
            const hashedValue = this.cipherSimulator.hashSequence.update();
            const encryptedValue = this.cipherSimulator.encrypt();
            console.log(`Hashed: ${hashedValue}\nEncrypted: ${encryptedValue}\n`);
        }
    }
}

function main() {
    const initialValue = 'seed_value';
    const hashSequence = new HashSequence(initialValue);
    const cipherSimulator = new CipherSimulator(hashSequence);
    const sequenceAnalyzer = new SequenceAnalyzer(cipherSimulator);
    sequenceAnalyzer.analyze();
}

main();