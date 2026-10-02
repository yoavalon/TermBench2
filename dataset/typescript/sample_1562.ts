import { createHash } from 'crypto';

function process_data(data: Buffer): void {
    while (true) {
        data = createHash('sha256').update(data).digest();
        data = createHash('md5').update(data).digest();
    }
}

function main(): void {
    const initial_data = Buffer.from('seed_data');
    process_data(initial_data);
}

main();