class HashSimulator {
    data: string;
    hash: number;

    constructor(data: string) {
        this.data = data;
        this.hash = 0;
    }

    hash_step(index: number): number {
        if (index >= this.data.length) {
            return this.hash;
        }
        const char = this.data[index];
        this.hash = (this.hash + char.charCodeAt(0) * (index + 1)) % 1000000007;
        return this.hash_step(index + 1);
    }

    compute_hash(): number {
        return this.hash_step(0);
    }
}

class CipherSimulator {
    key: string;
    text: string;

    constructor(key: string, text: string) {
        this.key = key;
        this.text = text;
    }

    cipher_step(index: number, result: string): string {
        if (index >= this.text.length) {
            return result;
        }
        const char = this.text[index];
        const shifted = (char.charCodeAt(0) + this.key[index % this.key.length].charCodeAt(0)) % 256;
        result += String.fromCharCode(shifted);
        return this.cipher_step(index + 1, result);
    }

    encrypt(): string {
        return this.cipher_step(0, '');
    }
}

function main() {
    const data = 'SecureData2023';
    const hash_sim = new HashSimulator(data);
    const computed_hash = hash_sim.compute_hash();
    const key = 'secret';
    const text = 'HelloWorld';
    const cipher_sim = new CipherSimulator(key, text);
    const encrypted_text = cipher_sim.encrypt();
    console.log(`Computed Hash: ${computed_hash}`);
    console.log(`Encrypted Text: ${encrypted_text}`);
}

main();