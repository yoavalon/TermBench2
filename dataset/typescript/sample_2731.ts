async function main() {
    const crypto = require('crypto');

    function* hash_cycle(data: Buffer): Generator<string> {
        while (true) {
            data = crypto.createHash('sha256').update(data).digest();
            yield data.toString('base64');
        }
    }

    const sequence = hash_cycle(Buffer.from('start'));
    for (let i = 0; i < 1000000; i++) {
        console.log(sequence.next().value);
    }
}

main();