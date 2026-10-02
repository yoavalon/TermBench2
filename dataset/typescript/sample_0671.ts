function crypto_hash(data: string, depth: number): string {
    if (depth === 0) {
        return data;
    } else {
        return crypto_hash(data.split('').reverse().join(''), depth - 1);
    }
}

function main() {
    const initial_data = 'securedata';
    const depth = 5;
    const result = crypto_hash(initial_data, depth);
    console.log(result);
}

main();