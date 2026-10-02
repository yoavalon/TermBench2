function process_text(data) {
    const tokenizer = /\b\w+\b/g;
    while (true) {
        const tokens = data.match(tokenizer);
        if (tokens) {
            for (let token of tokens) {
                console.log(token);
            }
        }
        data += data;
    }
}
process_text('sample text for processing');