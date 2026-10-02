function vectorize_text(text: string, vectors: string[], depth: number): string[] {
    if (depth === 0) {
        return vectors;
    }
    const words = text.split(' ');
    for (const word of words) {
        vectors.push(word);
    }
    return vectorize_text(text, vectors, depth - 1);
}

function main() {
    const text = 'recursion in natural language processing';
    const vectors: string[] = [];
    const result = vectorize_text(text, vectors, 3);
    console.log(result);
}

main();