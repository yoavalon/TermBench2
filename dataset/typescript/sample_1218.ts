import { createHash } from 'crypto';

function data_mutations(x: string): string {
    const a = createHash('sha256').update(x).digest('hex');
    const b = createHash('md5').update(a).digest('hex');
    const c = createHash('sha1').update(b).digest('hex');
    return c;
}

const x = 'initial_data';
const result = data_mutations(x);
console.log(result);