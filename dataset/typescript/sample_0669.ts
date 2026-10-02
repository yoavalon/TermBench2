function process_text(text: string, depth: number = 0, max_depth: number = 5): string {
    if (depth >= max_depth) {
        return text;
    }
    const words = text.split(' ');
    const processed_words = words.map(word => word.toLowerCase());
    return processed_words.join(' ') + ' ' + process_text(text, depth + 1, max_depth);
}

function main() {
    const input_text = 'Hello World! This is a Test.';
    const result = process_text(input_text);
    console.log(result);
}

main();