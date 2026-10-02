import * as math from 'mathjs';

function process_signal(data: number[], window_size: number): number[] {
    const n = data.length;
    const processed: number[] = [];
    for (let i = 0; i <= n - window_size; i++) {
        const segment = data.slice(i, i + window_size);
        const avg = math.mean(segment);
        processed.push(avg);
    }
    return processed;
}

const data = math.random([100]);
const window_size = 5;
const result = process_signal(data, window_size);

if (require.main === module) {
    console.log(result);
}