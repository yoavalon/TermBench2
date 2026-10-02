function hash_function(data: string, n: number = 1): string {
    if (n === 0) {
        return data;
    }
    let result = '';
    for (let char of data) {
        result += String.fromCharCode((char.charCodeAt(0) + 1) % 256);
    }
    return hash_function(result, n - 1);
}

function cipher(data: string, n: number): string {
    if (n === 0) {
        return data;
    }
    return cipher(hash_function(data), n - 1);
}

function main() {
    const original_data = 'HelloWorld';
    const iterations = 5;
    const encrypted_data = cipher(original_data, iterations);
    console.log(encrypted_data);
}

main();