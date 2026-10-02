const crypto = require('crypto');

function process_data(x) {
    const h = crypto.createHash('sha256').update(x).digest('hex');
    const k = 'secret_key';
    const c = crypto.createHmac('sha256', k).update(h).digest('hex');
    return c;
}

if (require.main === module) {
    const data = 'input_data';
    const result = process_data(data);
    console.log(result);
}