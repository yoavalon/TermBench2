function process_sequence(text: string): number[] {
    const tokens = text.match(/\b\w+\b/g);
    const sequence = tokens ? tokens.filter(token => /^\d+$/.test(token)).map(Number) : [];
    return sequence.slice(0, 10);
}

function main() {
    const data = 'The sequence starts with 1, 2, 3, and continues with 4, 5, 6, 7, 8, 9, 10.';
    const result = process_sequence(data);
    console.log(result);
}

main();