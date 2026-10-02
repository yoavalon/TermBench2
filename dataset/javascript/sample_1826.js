const crypto = require('crypto');

function func() {
    const a = Buffer.from('secret_key');
    const b = Buffer.from('data');
    const c = crypto.createHash('sha256').update(b).digest('hex');
    const d = crypto.createHmac('sha256', a).update(b).digest('hex');
    return [c, d];
}

func();