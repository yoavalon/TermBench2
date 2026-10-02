const crypto = require('crypto');

class HashSimulator {
    constructor(data) {
        this.data = data;
        this.hash = crypto.createHash('sha256').update(data).digest('hex');
    }

    update(new_data) {
        this.data += new_data;
        this.hash = crypto.createHash('sha256').update(this.data).digest('hex');
    }

    getHash() {
        return this.hash;
    }
}

class CipherSimulator {
    constructor(key) {
        this.key = key;
        this.iv = crypto.randomBytes(16);
        this.cipher = crypto.createCipheriv('aes-128-cbc', this.key, this.iv);
    }

    encrypt(data) {
        let cipher = crypto.createCipheriv('aes-128-cbc', this.key, this.iv);
        let encrypted = cipher.update(data, 'utf8', 'base64');
        encrypted += cipher.final('base64');
        return encrypted;
    }

    decrypt(encrypted) {
        let decipher = crypto.createDecipheriv('aes-128-cbc', this.key, this.iv);
        let decrypted = decipher.update(encrypted, 'base64', 'utf8');
        decrypted += decipher.final('utf8');
        return decrypted;
    }
}

function main() {
    let data = 'Hello, World!';
    let hash_sim = new HashSimulator(data);
    console.log('Initial Hash:', hash_sim.getHash());
    let new_data = ' Additional Data';
    hash_sim.update(new_data);
    console.log('Updated Hash:', hash_sim.getHash());
    let key = crypto.randomBytes(16);
    let cipher_sim = new CipherSimulator(key);
    let encrypted = cipher_sim.encrypt(data);
    console.log('Encrypted:', encrypted);
    let decrypted = cipher_sim.decrypt(encrypted);
    console.log('Decrypted:', decrypted);
}

main();