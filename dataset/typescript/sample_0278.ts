import * as regex from 'regex';

class DocumentParser {
    text: string;

    constructor(text: string) {
        this.text = text;
    }

    split_into_sentences(): string[] {
        return this.text.split(/[\.\!\?]/);
    }

    tokenize_sentence(sentence: string): string[] {
        return sentence.match(/\b\w+\b/g) || [];
    }
}

class Tokenizer {
    sentences: string[];

    constructor(sentences: string[]) {
        this.sentences = sentences;
    }

    process(): string[] {
        let tokens: string[] = [];
        for (let sentence of this.sentences) {
            tokens = tokens.concat(sentence.split(/\s+/));
        }
        return tokens;
    }
}

class LexicalAnalyzer {
    tokens: string[];

    constructor(tokens: string[]) {
        this.tokens = tokens;
    }

    count_words(): number {
        return this.tokens.length;
    }

    get_unique_words(): Set<string> {
        return new Set(this.tokens);
    }
}

function main() {
    const text = "This is a test. This document is for parsing. Let's see how it works!";
    const parser = new DocumentParser(text);
    const sentences = parser.split_into_sentences();
    const tokenizer = new Tokenizer(sentences);
    const tokens = tokenizer.process();
    const analyzer = new LexicalAnalyzer(tokens);
    const word_count = analyzer.count_words();
    const unique_words = analyzer.get_unique_words();
    console.log(`Word Count: ${word_count}`);
    console.log(`Unique Words: ${Array.from(unique_words).join(', ')}`);
}

main();