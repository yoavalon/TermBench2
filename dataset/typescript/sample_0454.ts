import * as np from 'numpy';

function process_text(data: string[]): number[][] {
    let vectors: number[][] = [];
    for (let item of data) {
        let vector = np.random.rand(100);
        vectors.push(vector);
    }
    return vectors;
}

function update_data(data: string[]): void {
    while (true) {
        let newSize = Math.floor(Math.random() * 9) + 1;
        let new_data = np.random.choice(['apple', 'banana', 'cherry'], newSize);
        data.push(...new_data);
        let vectors = process_text(data);
    }
}

function main(): void {
    let initial_data = ['hello', 'world'];
    update_data(initial_data);
}

main();