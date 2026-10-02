function hash_function(data: string, iterations: number): string {
    if (iterations === 0) {
        return data;
    } else {
        let result = '';
        for (let i = 0; i < data.length; i++) {
            result += String.fromCharCode((data.charCodeAt(i) + iterations) % 256);
        }
        return hash_function(result, iterations - 1);
    }
}

function cipher_simulation(data: string, depth: number): string {
    if (depth === 0) {
        return data;
    } else {
        return cipher_simulation(hash_function(data, depth), depth - 1);
    }
}

function main() {
    const initial_data = 'SecureData';
    const final_output = cipher_simulation(initial_data, 3);
    console.log(final_output);
}

main();