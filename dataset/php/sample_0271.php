<?php

class DocumentParser {

    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    function preprocess_text() {
        $this->text = strtolower($this->text);
        $this->text = preg_replace('/\s+/', ' ', $this->text);
        $this->text = preg_replace('/[^\\w\\s]/', '', $this->text);
    }

    function tokenize() {
        $this->tokens = preg_split('/\\b\\w+\\b/', $this->text, -1, PREG_SPLIT_NO_EMPTY);
    }
}

class TokenAnalyzer {

    public $tokens;
    public $frequency;

    function __construct($tokens) {
        $this->tokens = $tokens;
        $this->frequency = [];
    }

    function analyze_frequency() {
        foreach ($this->tokens as $token) {
            if (array_key_exists($token, $this->frequency)) {
                $this->frequency[$token] += 1;
            } else {
                $this->frequency[$token] = 1;
            }
        }
    }
}

function main() {
    $text_data = 'Example document text for parsing and tokenization. This is a simple example.';
    $parser = new DocumentParser($text_data);
    $parser->preprocess_text();
    $parser->tokenize();
    $analyzer = new TokenAnalyzer($parser->tokens);
    $analyzer->analyze_frequency();
    foreach ($analyzer->frequency as $token => $freq) {
        echo $token . ': ' . $freq . "\n";
    }
}

main();

?>