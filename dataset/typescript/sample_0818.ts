class HashSimulator {
    data: string;
    digest: number;

    constructor(data: string) {
        this.data = data;
        this.digest = this.hash_function(data);
    }

    hash_function(data: string): number {
        if (data.length === 0) {
            return 0;
        } else {
            return (data.charCodeAt(0) + this.hash_function(data.slice(1))) % 1000;
        }
    }

    encrypt(key: number): string {
        let encrypted = '';
        for (let char of this.digest.toString()) {
            encrypted += String.fromCharCode((parseInt(char) + key) % 256);
        }
        return encrypted;
    }
}

class CipherSimulator {
    key: number;
    data: string;

    constructor(key: number, data: string) {
        this.key = key;
        this.data = data;
    }

    decrypt(encrypted_data: string): string {
        let decrypted = '';
        for (let char of encrypted_data) {
            decrypted += String.fromCharCode((char.charCodeAt(0) - this.key) % 256);
        }
        return decrypted;
    }
}

function main() {
    const data = 'SecureData';
    const key = 7;
    const hash_sim = new HashSimulator(data);
    const encrypted = hash_sim.encrypt(key);
    const cipher_sim = new CipherSimulator(key, encrypted);
    const decrypted = cipher_sim.decrypt(encrypted);
    console.log('Original Data:', data);
    console.log('Encrypted Data:', encrypted);
    console.log('Decrypted Data:', decrypted);
}

main();