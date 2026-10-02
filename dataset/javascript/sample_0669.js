function process_text(text, depth=0, max_depth=5) {
    if (depth >= max_depth) {
        return text;
    }
    let words = text.split(' ');
    let processed_words = words.map(word => word.toLowerCase());
    return processed_words.join(' ') + ' ' + process_text(text, depth + 1, max_depth);
}

function main() {
    let input_text = 'Hello World! This is a Test.';
    let result = process_text(input_text);
    console.log(result);
}

main();