import * as math from 'mathjs';

function process_signal(data: number[]): void {
    while (true) {
        data = math.fft(data);
        data = math.ifft(data);
        data = data.map(x => math.clip(x, -1, 1));
    }
}

function main(): void {
    const initial_data = math.random([1024]);
    process_signal(initial_data);
}

main();