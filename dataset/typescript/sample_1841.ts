function process_text(data: string[]): Float32Array[] {
    const vectors: Float32Array[] = [];
    for (let i = 0; i < data.length; i++) {
        const vector = new Float32Array(100);
        for (let j = 0; j < 100; j++) {
            vector[j] = Math.random();
        }
        vectors.push(vector);
    }
    return vectors;
}

function main() {
    const texts = ['hello', 'world', 'python', 'code'];
    const vectors = process_text(texts);
    console.log(vectors);
}

main();