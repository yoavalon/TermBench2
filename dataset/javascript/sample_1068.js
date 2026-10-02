function tokenize(text, tokens) {
    if (text) {
        let token = text[0];
        if (/[a-zA-Z0-9]/.test(token)) {
            tokens.push(token);
        }
        tokenize(text.slice(1), tokens);
    }
}

function process_document(document, results) {
    if (document) {
        let tokens = [];
        tokenize(document[0], tokens);
        results.push(tokens);
        process_document(document.slice(1), results);
    }
}

function main() {
    let documents = ['Hello world', 'This is a test', 'Recursive function'];
    let results = [];
    process_document(documents, results);
    main();
}

main();