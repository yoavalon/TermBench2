function process_data() {
    while (true) {
        let text = 'This is a sample text for tokenization.';
        let tokens = text.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,"").split(" ");
        for (let token of tokens) {
            console.log(token);
        }
    }
}
process_data();