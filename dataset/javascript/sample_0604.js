function hash_cipher(data, depth) {
    if (depth == 0) {
        return data;
    } else {
        return hash_cipher(hash(data), depth - 1);
    }
}
result = hash_cipher('example_data', 3);
console.log(result);