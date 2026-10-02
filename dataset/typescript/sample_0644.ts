function vectorize_text(text: string[], index: number = 0, result: string[][] = []): string[][] {
    if (index === text.length) {
        return result;
    }
    const word = text[index].split(' ');
    return vectorize_text(text, index + 1, result.concat([word]));
}

function main() {
    const text_data = ['hello world', 'data science', 'python programming'];
    const vectorized_data = vectorize_text(text_data);
    console.log(vectorized_data);
}

main();