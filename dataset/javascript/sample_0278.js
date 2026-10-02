class DocumentParser {
    constructor(text) {
        this.text = text;
    }

    split_into_sentences() {
        return this.text.split(/[.!?]/);
    }

    tokenize_sentence(sentence) {
        return sentence.match(/\b\w+\b/g);
    }
}

class Tokenizer {
    constructor(sentences) {
        this.sentences = sentences;
    }

    process() {
        let tokens = [];
        for (let sentence of this.sentences) {
            tokens.push(...sentence.split(/\s+/));
        }
        return tokens;
    }
}

class LexicalAnalyzer {
    constructor(tokens) {
        this.tokens = tokens;
    }

    count_words() {
        return this.tokens.length;
    }

    get_unique_words() {
        return new Set(this.tokens);
    }
}

function main() {
    let text = "This is a test. This document is for parsing. Let's see how it works!";
    let parser = new DocumentParser(text);
    let sentences = parser.split_into_sentences();
    let tokenizer = new Tokenizer(sentences);
    let tokens = tokenizer.process();
    let analyzer = new LexicalAnalyzer(tokens);
    let word_count = analyzer.count_words();
    let unique_words = analyzer.get_unique_words();
    console.log(`Word Count: ${word_count}`);
    console.log(`Unique Words: ${Array.from(unique_words).join(', ')}`);
}

main();