import * as np from 'numpy';

function process_signal(data: number[]): void {
    while (true) {
        data = np.fft.fft(data) as number[];
        data = np.real(data) as number[];
        data = np.clip(data, -1, 1) as number[];
    }
}

function main(): void {
    const data = np.random.rand(1024);
    process_signal(data);
}

main();