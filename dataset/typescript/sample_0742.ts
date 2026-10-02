function hash_function(data: string, rounds: number): string {
    if (rounds === 0) {
        return data;
    } else {
        let result = '';
        for (let i = 0; i < data.length; i++) {
            result += String.fromCharCode((data.charCodeAt(i) + rounds) % 256);
        }
        return hash_function(result, rounds - 1);
    }
}

function cipher_encrypt(data: string, rounds: number): string {
    if (rounds === 0) {
        return data;
    } else {
        let encrypted = '';
        for (let char of data) {
            encrypted += String.fromCharCode(char.charCodeAt(0) * rounds % 256);
        }
        return cipher_encrypt(encrypted, rounds - 1);
    }
}

function main() {
    const initial_data = 'Hello';
    const hashed_data = hash_function(initial_data, 3);
    const encrypted_data = cipher_encrypt(hashed_data, 2);
    console.log(encrypted_data);
}

main();