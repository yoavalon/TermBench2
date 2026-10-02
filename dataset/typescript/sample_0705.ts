function hash_function(data: string, rounds: number = 1000): string {
    if (rounds === 0) {
        return data;
    }
    let result = 0;
    for (let char of data) {
        result += (char.charCodeAt(0) * (rounds + char.charCodeAt(0)));
    }
    return hash_function(result.toString(), rounds - 1);
}

function encrypt(data: string, key: number): string {
    if (!data) {
        return '';
    }
    return String.fromCharCode(((data.charCodeAt(0) + key) % 256)) + encrypt(data.slice(1), key);
}

function main() {
    const data = 'securedata';
    const key = 7;
    const hashed_data = hash_function(data);
    const encrypted_data = encrypt(hashed_data, key);
    console.log(encrypted_data);
}

main();