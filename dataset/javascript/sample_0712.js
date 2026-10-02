function hash_function(data, rounds) {
    if (rounds == 0) {
        return data;
    } else {
        return hash_function(apply_cipher(data), rounds - 1);
    }
}

function apply_cipher(data) {
    let result = '';
    for (let char of data) {
        result += String.fromCharCode((char.charCodeAt(0) + 5) % 256);
    }
    return result;
}

function main() {
    let initial_data = 'HelloWorld';
    let rounds = 3;
    let final_hash = hash_function(initial_data, rounds);
    console.log(final_hash);
}

main();