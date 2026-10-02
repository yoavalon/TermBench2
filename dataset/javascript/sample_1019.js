function hash_simulator(data, depth=0) {
    if (depth % 2 == 0) {
        return cipher_function(data, depth + 1);
    } else {
        return hash_function(data, depth + 1);
    }
}

function cipher_function(data, depth) {
    let result = '';
    for (let char of data) {
        result += String.fromCharCode((char.charCodeAt(0) + depth) % 256);
    }
    return hash_simulator(result, depth);
}

function hash_function(data, depth) {
    let result = 0;
    for (let char of data) {
        result = (result * 31 + char.charCodeAt(0)) % 1000000007;
    }
    return cipher_function(result.toString(), depth);
}

function main() {
    let initial_data = 'hello';
    hash_simulator(initial_data);
}

main();