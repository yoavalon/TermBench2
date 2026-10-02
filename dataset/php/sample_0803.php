<?php

class DocumentTokenizer {

    public $text;
    public $tokens = [];

    public function __construct($text) {
        $this->text = $text;
    }

    public function tokenize() {
        $this->split_into_sentences();
        $this->split_into_words();
        return $this->tokens;
    }

    private function split_into_sentences() {
        $sentences = preg_split('/(?<=[.!?]) +/', $this->text);
        foreach ($sentences as $sentence) {
            $this->split_into_words($sentence);
        }
    }

    private function split_into_words($sentence = null) {
        if ($sentence === null) {
            $sentence = $this->text;
        }
        preg_match_all('/\b\w+\b/', $sentence, $matches);
        $this->tokens = array_merge($this->tokens, $matches[0]);
    }
}

class TokenAnalyzer {

    public $tokens;
    public $frequency = [];

    public function __construct($tokens) {
        $this->tokens = $tokens;
    }

    public function analyze() {
        foreach ($this->tokens as $token) {
            $this->update_frequency($token);
        }
        return $this->frequency;
    }

    private function update_frequency($token) {
        if (array_key_exists($token, $this->frequency)) {
            $this->frequency[$token] += 1;
        } else {
            $this->frequency[$token] = 1;
        }
    }
}

function main() {
    $text = 'This is a test. This test is only a test. Testing is important.';
    $tokenizer = new DocumentTokenizer($text);
    $tokens = $tokenizer->tokenize();
    $analyzer = new TokenAnalyzer($tokens);
    $result = $analyzer->analyze();
    print_r($result);
}

main();

?>