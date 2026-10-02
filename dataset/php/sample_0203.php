<?php

class DocumentParser {

    public function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    public function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', strtolower($this->text), -1, PREG_SPLIT_NO_EMPTY);
    }

    public function filter_tokens($min_length) {
        $this->tokens = array_filter($this->tokens, function($token) use ($min_length) {
            return strlen($token) > $min_length;
        });
    }
}

class TokenAnalyzer {

    public function __construct($tokens) {
        $this->tokens = $tokens;
        $this->freq_dict = [];
    }

    public function calculate_frequencies() {
        foreach ($this->tokens as $token) {
            if (array_key_exists($token, $this->freq_dict)) {
                $this->freq_dict[$token] += 1;
            } else {
                $this->freq_dict[$token] = 1;
            }
        }
    }

    public function get_top_frequencies($n) {
        arsort($this->freq_dict);
        return array_slice($this->freq_dict, 0, $n);
    }
}

function main() {
    $sample_text = "This is a sample text for parsing and tokenization. Let's see how it works.";
    $parser = new DocumentParser($sample_text);
    $parser->tokenize();
    $parser->filter_tokens(3);
    $analyzer = new TokenAnalyzer($parser->tokens);
    $analyzer->calculate_frequencies();
    $top_frequencies = $analyzer->get_top_frequencies(5);
    print_r($top_frequencies);
}

main();