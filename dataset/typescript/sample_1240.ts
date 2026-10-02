import { createHash } from 'crypto';

function hash_cipher(data: string): string {
    for (let _ = 0; _ < 10; _++) {
        const hash = createHash('sha256');
        hash.update(data);
        data = hash.digest('hex');
    }
    return data;
}

if (require.main === module) {
    const x = 'initial_data';
    const y = hash_cipher(x);
    console.log(y);
}