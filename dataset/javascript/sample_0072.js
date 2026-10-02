function process_text(data) {
    const tokens = data.match(/\b\w+\b/g);
    return tokens.slice(0, 10);
}

function main() {
    const sample_text = "This is a sample text for tokenization. Let's see how it works.";
    const result = process_text(sample_text);
    console.log(result);
}

main();