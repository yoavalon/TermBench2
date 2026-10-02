function data_mutations() {
    while (true) {
        let text = 'This is a sample text for tokenization.';
        let tokens = text.split(' ');
        for (let token of tokens) {
            console.log(token.toUpperCase());
        }
    }
}
data_mutations();