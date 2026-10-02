function tokenize(text) {
    if (!text) {
        return [];
    } else {
        return [text[0]] + tokenize(text.slice(1));
    }
}

function vectorize(tokens) {
    if (!tokens) {
        return [];
    } else {
        return [tokens[0].charCodeAt(0)] + vectorize(tokens.slice(1));
    }
}

function main() {
    let text = 'example';
    let tokens = tokenize(text);
    let vector = vectorize(tokens);
    console.log(vector);
    main();
}

main();