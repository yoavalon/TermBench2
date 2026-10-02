class HashSimulator {
    constructor(data) {
        this.data = data;
        this.digest = this.hash_function(data);
    }

    hash_function(data) {
        if (data.length === 0) {
            return 0;
        } else {
            return (data.charCodeAt(0) + this.hash_function(data.slice(1))) % 1000;
        }
    }

    encrypt(key) {
        let encrypted = '';
        for (let char of this.digest.toString()) {
            encrypted += String.fromCharCode((parseInt(char) + key) % 256);
        }
        return encrypted;
    }
}

class CipherSimulator {
    constructor(key, data) {
        this.key = key;
        this.data = data;
    }

    decrypt(encrypted_data) {
        let decrypted = '';
        for (let char of encrypted_data) {
            decrypted += String.fromCharCode((char.charCodeAt(0) - this.key) % 256);
        }
        return decrypted;
    }
}

function main() {
    let data = 'SecureData';
    let key = 7;
    let hash_sim = new HashSimulator(data);
    let encrypted = hash_sim.encrypt(key);
    let cipher_sim = new CipherSimulator(key, encrypted);
    let decrypted = cipher_sim.decrypt(encrypted);
    console.log('Original Data:', data);
    console.log('Encrypted Data:', encrypted);
    console.log('Decrypted Data:', decrypted);
}

main();