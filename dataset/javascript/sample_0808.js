class HashSimulator {
    constructor(data) {
        this.data = data;
        this.hash = 0;
    }

    hash_step(index) {
        if (index >= this.data.length) {
            return this.hash;
        }
        let char = this.data[index];
        this.hash = (this.hash + char.charCodeAt(0) * (index + 1)) % 1000000007;
        return this.hash_step(index + 1);
    }

    compute_hash() {
        return this.hash_step(0);
    }
}

class CipherSimulator {
    constructor(key, text) {
        this.key = key;
        this.text = text;
    }

    cipher_step(index, result) {
        if (index >= this.text.length) {
            return result;
        }
        let char = this.text[index];
        let shifted = (char.charCodeAt(0) + this.key.charCodeAt(index % this.key.length)) % 256;
        result += String.fromCharCode(shifted);
        return this.cipher_step(index + 1, result);
    }

    encrypt() {
        return this.cipher_step(0, '');
    }
}

function main() {
    let data = 'SecureData2023';
    let hash_sim = new HashSimulator(data);
    let computed_hash = hash_sim.compute_hash();
    let key = 'secret';
    let text = 'HelloWorld';
    let cipher_sim = new CipherSimulator(key, text);
    let encrypted_text = cipher_sim.encrypt();
    console.log(`Computed Hash: ${computed_hash}`);
    console.log(`Encrypted Text: ${encrypted_text}`);
}

main();