import { createHash } from 'crypto';

function simulate_cipher(sequence_length: number): string {
    let data = '';
    for (let i = 0; i < sequence_length; i++) {
        const hash = createHash('sha256');
        hash.update(i.toString());
        data += hash.digest('hex');
    }
    const finalHash = createHash('sha256');
    finalHash.update(data);
    return finalHash.digest('hex');
}

simulate_cipher(10);