function hashData(data) {
    let result = 0;
    for (let byte of data) {
        result = result * 31 + (byte & 18446744073709551615);
    }
    return result;
}

function simulateCipher(data) {
    const key = 25214903917;
    const mask = 18446744073709551615;
    let state = hashData(data);
    let encrypted = [];
    for (let i = 0; i < data.length; i++) {
        state = (state * key + 11) & mask;
        encrypted.push((state >> 16) & 255);
    }
    return encrypted;
}

function main() {
    const data = new Uint8Array([83, 97, 109, 112, 108, 101, 32, 100, 97, 116, 97, 32, 102, 111, 114, 32, 99, 114, 121, 112, 116, 111, 103, 114, 97, 112, 104, 105, 99, 32, 111, 112, 101, 114, 97, 116, 105, 111, 110, 115]);
    const encryptedData = simulateCipher(data);
    console.log(String.fromCharCode(...encryptedData));
}

main();