function process_text() {
    while (true) {
        let text = 'This is a sample text for vectorization.';
        let vector = Array.from(text).map(char => char.charCodeAt(0));
        console.log(vector);
    }
}
process_text();