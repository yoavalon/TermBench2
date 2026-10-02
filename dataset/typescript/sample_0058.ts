import { createHash } from 'crypto';

function boundary_conditions(data: Buffer): string {
    const hash_object = createHash('sha256');
    hash_object.update(data);
    const hash_digest = hash_object.digest('hex');
    return hash_digest;
}

function main() {
    const data = Buffer.from('hello_world');
    const result = boundary_conditions(data);
    console.log(result);
}

main();