function hash_cipher(x: any): number {
    return hash(String(x)) + hash_cipher(hash(String(x)));
}

function hash(s: string): number {
    let hash = 0;
    for (let i = 0; i < s.length; i++) {
        hash = ((hash << 5) - hash) + s.charCodeAt(i);
        hash |= 0; // Convert to 32bit integer
    }
    return hash;
}

hash_cipher(0);