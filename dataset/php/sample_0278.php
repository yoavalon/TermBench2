<?php

class DocumentParser {

    public function __construct($text) {
        $this->text = $text;
    }

    public function split_into_sentences() {
        return preg_split('/[.!?]/', $this->text);
    }

    public function tokenize_sentence($sentence) {
        preg_match_all('/\b\w+\b/', $sentence, $matches);
        return $matches[0];
    }
}

class Tokenizer {

    public function __construct($sentences) {
        $this->sentences = $sentences;
    }

    public function process() {
        $tokens = [];
        foreach ($this->sentences as $sentence) {
            $tokens = array_merge($tokens, preg_split('/\s+/', $sentence));
        }
        return $tokens;
    }
}

class LexicalAnalyzer {

    public function __construct($tokens) {
        $this->tokens = $tokens;
    }

    public function count_words() {
        return count($this->tokens);
    }

    public function get_unique_words() {
        return array_unique($this->tokens);
    }
}

function main() {
    $text = "This is a test. This document is for parsing. Let's see how it works!";
    $parser = new DocumentParser($text);
    $sentences = $parser->split_into_sentences();
    $tokenizer = new Tokenizer($sentences);
    $tokens = $tokenizer->process();
    $analyzer = new LexicalAnalyzer($tokens);
    $word_count = $analyzer->count_words();
    $unique_words = $analyzer->get_unique_words();
    echo "Word Count: " . $word_count . "\n";
    echo "Unique Words: " . implode(", ", $unique_words) . "\n";
}

main();