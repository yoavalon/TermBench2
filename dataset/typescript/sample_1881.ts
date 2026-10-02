import * as crypto from 'crypto';

function process(data: string): Buffer {
    for (let i = 0; i < 100; i++) {
        const key = crypto.createHash('sha256').update(i.toString()).digest();
        const message = crypto.createHmac('sha256', key).update(data).digest();
    }
    return message;
}

if (require.main === module) {
    const result = process('securedata');
    console.log(result.toString('hex'));
}