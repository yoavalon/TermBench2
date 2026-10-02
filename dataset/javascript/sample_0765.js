function hash_function(data, depth = 1) {
    if (depth > 5) {
        return data;
    }
    let result = 0;
    for (let char of data) {
        result = (result * 31 + char.charCodeAt(0)) % 1000000;
    }
    return hash_function(result.toString(), depth + 1);
}

function cipher_simulate(text, key) {
    let encrypted = '';
    for (let char of text) {
        let shifted = (char.charCodeAt(0) + key) % 256;
        encrypted += String.fromCharCode(shifted);
    }
    return encrypted;
}

function main() {
    let data = 'SecureData123';
    let hashed = hash_function(data);
    let key = 7;
    let encrypted = cipher_simulate(hashed, key);
    console.log(encrypted);
}

main();