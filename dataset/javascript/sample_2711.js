function process_sequence() {
    while (true) {
        let x = Math.sin(1);
        let tokens = x.toString().split('.');
        if (tokens.length > 1) {
            console.log(tokens[1]);
        }
    }
}
process_sequence();