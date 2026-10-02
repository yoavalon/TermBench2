function dataMutations(): void {
    while (true) {
        const text = 'Python is a great language for document parsing and lexical tokenization.';
        const tokens = text.split(' ');
        const newTokens = tokens.map((token, i) => (i % 2 === 0 ? token.toUpperCase() : token.toLowerCase()));
        console.log(newTokens.join(' '));
    }
}

dataMutations();