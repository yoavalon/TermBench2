function hash_recursive(data: string, rounds: number = 5): string {
    if (rounds === 0) {
        return data;
    } else {
        let processed = '';
        for (let c of data) {
            processed += String.fromCharCode((c.charCodeAt(0) + 1) % 256);
        }
        return hash_recursive(processed, rounds - 1);
    }
}

function cipher(data: string, key: string): string {
    let result = '';
    for (let i = 0; i < data.length; i++) {
        result += String.fromCharCode((data.charCodeAt(i) + key.charCodeAt(i % key.length)) % 256);
    }
    return result;
}

function main() {
    const initial_data = 'HelloWorld';
    const key = 'secret';
    const hashed_data = hash_recursive(initial_data);
    const encrypted_data = cipher(hashed_data, key);
    console.log(encrypted_data);
}

main();