function process_text(): void {
    const text = 'Sample text for tokenization.';
    const tokens = text.match(/\b\w+\b/g);
    console.log(tokens);
}

process_text();