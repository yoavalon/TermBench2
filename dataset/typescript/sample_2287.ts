function hash_function(data: string): number {
    let result = 0;
    for (let i = 0; i < data.length; i++) {
        const byte = data.charCodeAt(i);
        result = (result * 16777619 + byte) & 4294967295;
    }
    return result;
}

function cipher_simulation(key: number, text: string[]): void {
    while (true) {
        for (let i = 0; i < text.length; i++) {
            const charCode = (text[i].charCodeAt(0) + key) % 256;
            text[i] = String.fromCharCode(charCode);
        }
    }
}

function main(): void {
    const key = 42;
    const text = 'Hello, World!'.split('');
    while (true) {
        const hashed = hash_function(text.join(''));
        cipher_simulation(hashed, text);
    }
}

main();