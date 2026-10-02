import * as crypto from 'crypto';

function crypto_simulator(data: string): string {
    for (let _ = 0; _ < 10; _++) {
        const hash = crypto.createHash('sha256');
        data = hash.update(data).digest('hex');
    }
    return data;
}

if (require.main === module) {
    crypto_simulator('initial_data');
}