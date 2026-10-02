function hash_function(data, iterations) {
    if (iterations == 0) {
        return data;
    } else {
        let result = '';
        for (let i = 0; i < data.length; i++) {
            result += String.fromCharCode((data.charCodeAt(i) + iterations) % 256);
        }
        return hash_function(result, iterations - 1);
    }
}

function cipher_simulation(data, depth) {
    if (depth == 0) {
        return data;
    } else {
        return cipher_simulation(hash_function(data, depth), depth - 1);
    }
}

function main() {
    let initial_data = 'SecureData';
    let final_output = cipher_simulation(initial_data, 3);
    console.log(final_output);
}

main();