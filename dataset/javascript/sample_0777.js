function hash_function(data, n = 1) {
    if (n == 0) {
        return data;
    }
    let result = '';
    for (let char of data) {
        result += String.fromCharCode((char.charCodeAt(0) + 1) % 256);
    }
    return hash_function(result, n - 1);
}

function cipher(data, n) {
    if (n == 0) {
        return data;
    }
    return cipher(hash_function(data), n - 1);
}

function main() {
    let original_data = 'HelloWorld';
    let iterations = 5;
    let encrypted_data = cipher(original_data, iterations);
    console.log(encrypted_data);
}

main();