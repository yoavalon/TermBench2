import * as crypto from 'crypto';

class HashSimulator {
    data: Buffer;
    hash_algorithms: string[];

    constructor(data: string) {
        this.data = Buffer.from(data);
        this.hash_algorithms = ['md5', 'sha1', 'sha256', 'sha512'];
    }

    apply_hash(algorithm: string): string {
        const hasher = crypto.createHash(algorithm);
        hasher.update(this.data);
        return hasher.digest('hex');
    }

    simulate_hashes(): Record<string, string> {
        const results: Record<string, string> = {};
        for (const algo of this.hash_algorithms) {
            results[algo] = this.apply_hash(algo);
        }
        return results;
    }
}

class CipherSimulator {
    data: Buffer;
    key: Buffer;

    constructor(data: string, key: string) {
        this.data = Buffer.from(data);
        this.key = Buffer.from(key);
    }

    xor_cipher(): Buffer {
        const encrypted = Buffer.alloc(this.data.length);
        for (let i = 0; i < this.data.length; i++) {
            encrypted[i] = this.data[i] ^ this.key[i % this.key.length];
        }
        return encrypted;
    }

    simulate_ciphers(): Record<string, Buffer> {
        return { 'xor': this.xor_cipher() };
    }
}

class DataMutator {
    data: Buffer;
    key: Buffer;

    constructor(data: string) {
        this.data = Buffer.from(data, 'utf-8');
        this.key = Buffer.from('secret');
    }

    mutate(): Record<string, any> {
        const hash_sim = new HashSimulator(this.data.toString());
        const cipher_sim = new CipherSimulator(this.data.toString(), this.key.toString());
        const hashes = hash_sim.simulate_hashes();
        const ciphers = cipher_sim.simulate_ciphers();
        return { 'hashes': hashes, 'ciphers': ciphers };
    }
}

function main() {
    const data = 'Sample data for cryptographic simulation';
    const mutator = new DataMutator(data);
    const result = mutator.mutate();
    console.log(result);
}

main();