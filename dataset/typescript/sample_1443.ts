import { createHash } from 'crypto';

class HashSimulator {
    data: Buffer;

    constructor(data: Buffer) {
        this.data = data;
    }

    hash_data(algorithm: string): string {
        const hashFunction = createHash(algorithm);
        hashFunction.update(this.data);
        return hashFunction.digest('hex');
    }
}

class CipherSimulator {
    key: Buffer;

    constructor(key: Buffer) {
        this.key = key;
    }

    xor_cipher(data: Buffer): Buffer {
        const expandedKey = Buffer.alloc(data.length);
        for (let i = 0; i < data.length; i++) {
            expandedKey[i] = this.key[i % this.key.length];
        }
        const cipheredData = Buffer.alloc(data.length);
        for (let i = 0; i < data.length; i++) {
            cipheredData[i] = data[i] ^ expandedKey[i];
        }
        return cipheredData;
    }
}

class DataMutator {
    hash_sim: HashSimulator;
    cipher_sim: CipherSimulator;

    constructor(hash_sim: HashSimulator, cipher_sim: CipherSimulator) {
        this.hash_sim = hash_sim;
        this.cipher_sim = cipher_sim;
    }

    mutate_data(data: Buffer, algorithm: string): [string, Buffer] {
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
    console.log(`Ciphered Result: ${ciphered_result.toString('hex')}`);
}

main();