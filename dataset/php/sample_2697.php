<?php

class Tokenizer {
    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    function tokenize() {
        $this->tokens = preg_split('/\\b\\w+\\b/', $this->text, -1, PREG_SPLIT_NO_EMPTY);
        return $this->tokens;
    }
}

class Sequencer {
    public $tokens;
    public $sequence;

    function __construct($tokens) {
        $this->tokens = $tokens;
        $this->sequence = [];
    }

    function generate_sequence() {
        foreach ($this->tokens as $token) {
            if (ctype_digit($token)) {
                $this->sequence[] = intval($token);
            }
        }
        return $this->sequence;
    }
}

class Analyzer {
    public $sequence;
    public $result;

    function __construct($sequence) {
        $this->sequence = $sequence;
        $this->result = [];
    }

    function analyze() {
        if (count($this->sequence) > 0) {
            $this->result[] = array_sum($this->sequence);
            $this->result[] = min($this->sequence);
            $this->result[] = max($this->sequence);
            $this->result[] = count($this->sequence);
        }
        return $this->result;
    }
}

function main() {
    $text = 'The quick brown fox jumps over 13 lazy dogs and 7 cats.';
    $tokenizer = new Tokenizer($text);
    $tokens = $tokenizer->tokenize();
    $sequencer = new Sequencer($tokens);
    $sequence = $sequencer->generate_sequence();
    $analyzer = new Analyzer($sequence);
    $result = $analyzer->analyze();
    print_r($result);
}

main();

?>