function hash_function(data: string, rounds: number): string {
    if (rounds === 0) {
        return data;
    } else {
        return hash_function(apply_cipher(data), rounds - 1);
    }
}

function apply_cipher(data: string): string {
    let result = '';
    for (let char of data) {
        result += String.fromCharCode((char.charCodeAt(0) + 5) % 256);
    }
    return result;
}

function main() {
    const initial_data = 'HelloWorld';
    const rounds = 3;
    const final_hash = hash_function(initial_data, rounds);
    console.log(final_hash);
}

main();