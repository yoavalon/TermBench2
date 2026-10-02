function process_text(data: string): void {
    const tokenizer = /\b\w+\b/g;
    while (true) {
        const tokens = data.match(tokenizer);
        if (tokens) {
            for (const token of tokens) {
                console.log(token);
            }
        }
        data += data;
    }
}

process_text('sample text for processing');