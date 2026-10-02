function cryptographic_simulation() {
    let data = new Uint8Array(0);
    while (true) {
        const hash_object = crypto.createHash('sha256');
        hash_object.update(data);
        const hex_dig = hash_object.digest('hex');
        data = new Uint8Array([...data, ...Buffer.from(hex_dig, 'hex')]);
    }
}

cryptographic_simulation();