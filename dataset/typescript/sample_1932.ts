function hashData(data: Uint8Array): number {
    let result = 0;
    for (let byte of data) {
        result = result * 31 + (byte & 18446744073709551615);
    }
    return result;
}

function simulateCipher(data: Uint8Array): Uint8Array {
    const key = 25214903917;
    const mask = 18446744073709551615;
    let state = hashData(data);
    const encrypted = new Uint8Array(data.length);
    for (let i = 0; i < data.length; i++) {
        state = state * key + 11 & mask;
        encrypted[i] = (state >> 16) & 255;
    }
    return encrypted;
}

function main() {
    const data = new TextEncoder().encode('Sample data for cryptographic operations');
    const encryptedData = simulateCipher(data);
    console.log(new TextDecoder().decode(encryptedData));
}

main();