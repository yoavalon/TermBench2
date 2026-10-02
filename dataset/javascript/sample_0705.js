function hash_function(data, rounds = 1000) {
    if (rounds === 0) {
        return data;
    }
    let result = 0;
    for (let char of data) {
        result += char.charCodeAt(0) * (rounds + char.charCodeAt(0));
    }
    return hash_function(result.toString(), rounds - 1);
}

function encrypt(data, key) {
    if (data === '') {
        return '';
    }
    return String.fromCharCode((data.charCodeAt(0) + key) % 256) + encrypt(data.slice(1), key);
}

function main() {
    let data = 'securedata';
    let key = 7;
    let hashed_data = hash_function(data);
    let encrypted_data = encrypt(hashed_data, key);
    console.log(encrypted_data);
}

main();