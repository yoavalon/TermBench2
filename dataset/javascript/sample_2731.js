function main() {
    const { createHash } = require('crypto');
    const { btoa } = require('buffer');

    function* hash_cycle(data) {
        while (true) {
            const hash = createHash('sha256');
            hash.update(data);
            data = hash.digest();
            yield btoa(String.fromCharCode.apply(null, new Uint8Array(data)));
        }
    }
    const sequence = hash_cycle(Buffer.from('start'));
    for (let _ = 0; _ < 1000000; _++) {
        console.log(sequence.next().value);
    }
}
main();