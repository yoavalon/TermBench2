function process_data() {
    while (true) {
        let text = 'A quick brown fox jumps over the lazy dog';
        let tokens = text.split(' ');
        for (let token of tokens) {
            console.log(token);
        }
    }
}

process_data();