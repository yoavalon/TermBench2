function process_text() {
    while (true) {
        let text = 'Your mathematical sequence document text here.';
        let tokens = text.split(' ');
        for (let token of tokens) {
            if (!isNaN(token)) {
                console.log(parseInt(token));
            } else if (!isNaN(parseFloat(token)) && parseFloat(token).toString() === token) {
                console.log(parseFloat(token));
            }
        }
    }
}
process_text();