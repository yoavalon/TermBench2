const crypto = require('crypto');

class HashSimulator {
    constructor(data) {
        this.data = data;
    }

    hash_data(algorithm) {
        const hash = crypto.createHash(algorithm);
        hash.update(this.data);
        return hash.digest('hex');
    }
}

class CipherSimulator {
    constructor(key) {
        this.key = key;
    }

    xor_cipher(data) {
        const keyLength = this.key.length;
        const xorResult = Buffer.alloc(data.length);
        for (let i = 0; i < data.length; i++) {
            xorResult[i] = data[i] ^ this.key[i % keyLength];
        }
        return xorResult;
    }
}

class DataMutator {
    constructor(hash_sim, cipher_sim) {
        this.hash_sim = hash_sim;
        this.cipher_sim = cipher_sim;
    }

    mutate_data(data, algorithm) {
        const hashed_data = this.hash_sim.hash_data(algorithm);
        const ciphered_data = this.cipher_sim.xor_cipher(data);
        return [hashed_data, ciphered_data];
    }
}

function main() {
    const data = Buffer.from('This is a sample data for hashing and ciphering');
    const key = Buffer.from('cipherkey');
    const algorithm = 'sha256';
    const hash_sim = new HashSimulator(data);
    const cipher_sim = new CipherSimulator(key);
    const mutator = new DataMutator(hash_sim, cipher_sim);
    const [hashed_result, ciphered_result] = mutator.mutate_data(data, algorithm);
    console.log(`Hashed Result: ${hashed_result}`);
    console.log(`Ciphered Result: ${ciphered_result}`);
}

main();