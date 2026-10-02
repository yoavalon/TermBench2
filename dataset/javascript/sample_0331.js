const crypto = require('crypto');

function non_terminating_function(x) {
    while (true) {
        x = crypto.createHash('sha256').update(x).digest('hex');
        x = crypto.createHash('md5').update(x).digest('hex');
    }
}

non_terminating_function('start');