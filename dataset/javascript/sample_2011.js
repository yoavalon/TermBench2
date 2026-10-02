const crypto = require('crypto');

function hash_function(data) {
    const sha256 = crypto.createHash('sha256');
    sha256.update(data);
    return sha256.digest('hex');
}

function cipher_simulation(key, text) {
    const encrypted = [];
    for (let i = 0; i < text.length; i++) {
        const k = key[i % key.length];
        const e = String.fromCharCode((text.charCodeAt(i) + k.charCodeAt(0)) % 256);
        encrypted.push(e);
    }
    return encrypted.join('');
}

function analyze_hash_collision(data_set) {
    const hash_map = {};
    let collisions = 0;
    for (const data of data_set) {
        const hash_value = hash_function(data);
        if (hash_map[hash_value]) {
            collisions += 1;
        } else {
            hash_map[hash_value] = data;
        }
    }
    return collisions;
}

function main() {
    const data = 'SensitiveData123';
    const key = 'SecretKey';
    const encrypted_data = cipher_simulation(key, data);
    const hash_value = hash_function(encrypted_data);
    const collision_count = analyze_hash_collision([encrypted_data, encrypted_data]);
    console.log('Encrypted Data:', encrypted_data);
    console.log('Hash Value:', hash_value);
    console.log('Collision Count:', collision_count);
}

main();