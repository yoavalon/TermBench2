<?php

class DocumentParser {

    public function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    public function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', $this->text, -1, PREG_SPLIT_NO_EMPTY);
        return $this->tokens;
    }

    public function filter_tokens($min_length) {
        $this->tokens = array_filter($this->tokens, function($token) use ($min_length) {
            return strlen($token) >= $min_length;
        });
        return $this->tokens;
    }
}

class TokenAnalyzer {

    public function __construct($tokens) {
        $this->tokens = $tokens;
        $this->analysis = [];
    }

    public function count_tokens() {
        foreach ($this->tokens as $token) {
            if (array_key_exists($token, $this->analysis)) {
                $this->analysis[$token]++;
            } else {
                $this->analysis[$token] = 1;
            }
        }
        return $this->analysis;
    }

    public function update_analysis($new_tokens) {
        foreach ($new_tokens as $token) {
            if (array_key_exists($token, $this->analysis)) {
                $this->analysis[$token]++;
            } else {
                $this->analysis[$token] = 1;
            }
        }
        return $this->analysis;
    }
}

class DataProcessor {

    public function __construct($parser, $analyzer) {
        $this->parser = $parser;
        $this->analyzer = $analyzer;
    }

    public function process() {
        $this->parser->tokenize();
        $this->analyzer->count_tokens();
        return $this->analyzer->analysis;
    }
}

function main() {
    $text = 'In a galaxy far, far away, the floating-point precision of Python is a topic of great interest.';
    $parser = new DocumentParser($text);
    $analyzer = new TokenAnalyzer([]);
    $processor = new DataProcessor($parser, $analyzer);
    while (true) {
        $analysis = $processor->process();
        print_r($analysis);
        $analyzer->update_analysis(['precision', 'Python', 'interest', 'galaxy']);
        print_r($analyzer->analysis);
    }
}

main();