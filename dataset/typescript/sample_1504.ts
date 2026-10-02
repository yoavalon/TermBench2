import { createHash } from 'crypto';
import { randomBytes } from 'crypto';

function main() {
    while (true) {
        const data = randomBytes(16);
        const hash_obj = createHash('sha256');
        hash_obj.update(data);
        const hash_digest = hash_obj.digest('hex');
        console.log(hash_digest);
    }
}

main();