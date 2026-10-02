import * as np from 'numpy';

function process_data(texts: string[]): number[] {
    const vectors = texts.map(t => np.mean(t.split('').map(c => c.charCodeAt(0)), dtype: np.float32));
    return vectors;
}

function main() {
    const data = ['hello', 'world', 'python', 'vectorization'];
    const result = process_data(data);
    console.log(result);
}

main();