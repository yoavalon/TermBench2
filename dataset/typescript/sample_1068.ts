function tokenize(text: string, tokens: string[]): void {
    if (text) {
        const token = text[0];
        if (/\w/.test(token)) {
            tokens.push(token);
        }
        tokenize(text.slice(1), tokens);
    }
}

function process_document(document: string[], results: string[][]): void {
    if (document.length > 0) {
        const tokens: string[] = [];
        tokenize(document[0], tokens);
        results.push(tokens);
        process_document(document.slice(1), results);
    }
}

function main(): void {
    const documents: string[] = ['Hello world', 'This is a test', 'Recursive function'];
    const results: string[][] = [];
    process_document(documents, results);
    main();
}

main();