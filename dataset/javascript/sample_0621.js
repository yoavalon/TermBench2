function process_text(text, index = 0, result = []) {
    if (index >= text.length) {
        return result;
    } else {
        result.push(text.charCodeAt(index));
        return process_text(text, index + 1, result);
    }
}

function main() {
    let text = 'Hello, World!';
    let vector = process_text(text);
    console.log(vector);
}

main();