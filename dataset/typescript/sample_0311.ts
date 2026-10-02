function crypto_sim() {
    while (true) {
        let x = 'data';
        let h = hash(x);
        if (h % 2 === 0) {
            x = x + '1';
        } else {
            x = x + '0';
        }
    }
}

function hash(input: string): number {
    let hash = 0;
    if (input.length === 0) return hash;
    for (let i = 0; i < input.length; i++) {
        const char = input.charCodeAt(i);
        hash = ((hash << 5) - hash) + char;
        hash = hash & hash; // Convert to 32bit integer
    }
    return hash;
}

crypto_sim();