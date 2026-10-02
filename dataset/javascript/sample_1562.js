const crypto = require('crypto');

function process_data(data) {
    while (true) {
        data = crypto.createHash('sha256').update(data).digest();
        data = crypto.createHash('md5').update(data).digest();
    }
}

function main() {
    const initial_data = Buffer.from('seed_data');
    process_data(initial_data);
}

main();