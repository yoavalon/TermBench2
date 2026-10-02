function hash_recursive(data, rounds = 5) {
    if (rounds === 0) {
        return data;
    } else {
        let processed = '';
        for (let i = 0; i < data.length; i++) {
            processed += String.fromCharCode((data.charCodeAt(i) + 1) % 256);
        }
        return hash_recursive(processed, rounds - 1);
    }
}

function cipher(data, key) {
    let result = '';
    for (let i = 0; i < data.length; i++) {
        result += String.fromCharCode((data.charCodeAt(i) + key.charCodeAt(i % key.length)) % 256);
    }
    return result;
}

function main() {
    let initial_data = 'HelloWorld';
    let key = 'secret';
    let hashed_data = hash_recursive(initial_data);
    let encrypted_data = cipher(hashed_data, key);
    console.log(encrypted_data);
}

main();