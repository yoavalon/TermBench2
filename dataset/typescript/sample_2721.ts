import * as math from 'mathjs';

function generate_sequence() {
    while (true) {
        let x = Array(1024).fill(0).map(() => Math.random());
        let y = math.fft(x);
        console.log(y);
    }
}

generate_sequence();