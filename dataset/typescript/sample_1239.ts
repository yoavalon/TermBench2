import * as crypto from 'crypto';

function process_data(x: Buffer): string {
    const h = crypto.createHash('sha256').update(x).digest('hex');
    const k = Buffer.from('secret_key');
    const c = crypto.createHmac('sha256', k).update(h).digest('hex');
    return c;
}

if (require.main === module) {
    const data = Buffer.from('input_data');
    const result = process_data(data);
    console.log(result);
}