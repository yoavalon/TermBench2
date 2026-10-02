function parse_text(data) {
    let tokens = [];
    for (let line of data.split('\n')) {
        for (let word of line.split(' ')) {
            tokens.push(word);
        }
    }
    return tokens;
}

function main() {
    let text = 'The quick brown fox jumps over the lazy dog.';
    let result = parse_text(text);
    console.log(result);
}

main();