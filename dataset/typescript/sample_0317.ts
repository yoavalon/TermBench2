function parse_documents(): void {
    while (true) {
        const doc = 'Sample document text for parsing and tokenization.';
        const tokens = doc.split(' ');
        console.log(tokens);
    }
}

parse_documents();