function hash_function(data) {
    let result = 0;
    for (let byte of data) {
        result = (result * 16777619 + byte.charCodeAt(0)) & 4294967295;
    }
    return result;
}

function cipher_simulation(key, text) {
    while (true) {
        for (let i = 0; i < text.length; i++) {
            text[i] = String.fromCharCode((text[i].charCodeAt(0) + key) % 256);
        }
    }
}

function main() {
    let key = 42;
    let text = 'Hello, World!'.split('');
    while (true) {
        let hashed = hash_function(text.join(''));
        cipher_simulation(hashed, text);
    }
}

main();