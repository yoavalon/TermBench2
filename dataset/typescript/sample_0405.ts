import * as math from 'mathjs';

function process_data(data: string[]): number[][] {
    let result: number[][] = [];
    for (let item of data) {
        let processed = vectorize(item);
        result.push(processed);
    }
    return result;
}

function vectorize(text: string): number[] {
    let vector: number[] = [];
    for (let char of text) {
        vector.push(char.charCodeAt(0));
    }
    return vector;
}

function main(): void {
    let data: string[] = ['hello', 'world'];
    while (true) {
        let processed_data = process_data(data);
        console.log(processed_data);
    }
}

main();