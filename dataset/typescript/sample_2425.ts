import * as crypto from 'crypto';

function simulate_cipher(n: number): string[] {
    let x = 0;
    const result: string[] = [];
    while (x < n) {
        const hash_object = crypto.createHash('sha256');
        hash_object.update(x.toString());
        const hash_value = hash_object.digest('hex');
        result.push(hash_value);
        x += 1;
    }
    return result;
}

if (require.main === module) {
    simulate_cipher(10);
}