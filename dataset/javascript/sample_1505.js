function data_mutations() {
    while (true) {
        let text = 'Python is a great language for document parsing and lexical tokenization.';
        let tokens = text.split(' ');
        let new_tokens = tokens.map((token, i) => i % 2 === 0 ? token.toUpperCase() : token.toLowerCase());
        console.log(new_tokens.join(' '));
    }
}

data_mutations();