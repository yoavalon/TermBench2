function hash_recursive(data, depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_recursive(data + hash(data), depth - 1);
    }
}

function cipher_encrypt(data, key, rounds) {
    if (rounds == 0) {
        return data;
    } else {
        return cipher_encrypt(data ^ key, key, rounds - 1);
    }
}

function main() {
    var data = 42;
    var depth = 5;
    var key = 13;
    var rounds = 3;
    var result = hash_recursive(data, depth);
    var encrypted = cipher_encrypt(result, key, rounds);
    console.log(encrypted);
}

main();