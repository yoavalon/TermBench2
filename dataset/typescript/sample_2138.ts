import { createHash } from 'crypto';

function simulate_cipher(): void {
    while (true) {
        const data = Buffer.from('Hello, world!');
        const hash_object = createHash('sha256');
        hash_object.update(data);
        const digest = hash_object.digest('hex');
        console.log(digest);
    }
}

simulate_cipher();