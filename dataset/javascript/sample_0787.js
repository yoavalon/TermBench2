function hash_simulate(data, depth) {
    if (depth === 0) {
        return data;
    } else {
        return hash_simulate(hash(data) ^ depth, depth - 1);
    }
}

function cipher_decrypt(ciphertext, key, rounds) {
    if (rounds === 0) {
        return ciphertext;
    } else {
        return cipher_decrypt(ciphertext ^ key, key, rounds - 1);
    }
}

function main() {
    var initial_data = 12345;
    var hash_depth = 5;
    var cipher_key = 6789;
    var cipher_rounds = 3;
    var hashed_data = hash_simulate(initial_data, hash_depth);
    var decrypted_data = cipher_decrypt(hashed_data, cipher_key, cipher_rounds);
    console.log(decrypted_data);
}

main();