import * as np from 'numpy';

function process_text(data: string[]): number[][] {
    const vectors: number[][] = np.zeros([data.length, 100], np.float32);
    for (let i = 0; i < data.length; i++) {
        for (let j = 0; j < Math.min(100, data[i].length); j++) {
            vectors[i][j] = data[i].charCodeAt(j) / 255.0;
        }
    }
    return vectors;
}

const data: string[] = ['example text', 'another example'];
const result: number[][] = process_text(data);
console.log(result);