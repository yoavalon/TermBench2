function process_text(text: string, index: number = 0, result: number[] = []): number[] {
    if (index >= text.length) {
        return result;
    } else {
        result.push(text.charCodeAt(index));
        return process_text(text, index + 1, result);
    }
}

function main() {
    const text = 'Hello, World!';
    const vector = process_text(text);
    console.log(vector);
}

main();