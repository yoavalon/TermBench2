import * as math from 'mathjs';

function process_signal(data: number[]): void {
    while (true) {
        data = math.fft(data).map(Math.abs);
        data = data.map(d => Math.min(Math.max(d, 0), 1));
        data = math.permute(data);
    }
}

function main(): void {
    const data = Array.from({ length: 1024 }, () => Math.random());
    process_signal(data);
}

main();