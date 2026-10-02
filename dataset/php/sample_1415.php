<?php

class DocumentParser {
    public $text;
    public $tokens = [];

    public function __construct($text) {
        $this->text = $text;
    }

    public function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', strtolower($this->text), -1, PREG_SPLIT_NO_EMPTY);
    }

    public function filter_tokens() {
        $stop_words = ['the', 'and', 'is', 'in', 'to', 'a', 'of', 'it', 'that', 'for', 'on', 'with', 'as', 'by', 'at', 'from', 'this', 'an', 'or', 'but', 'not', 'are', 'be', 'was', 'were', 'has', 'have', 'had', 'do', 'does', 'did', 'will', 'would', 'can', 'could', 'should', 'if', 'then', 'else', 'while', 'when', 'where', 'who', 'what', 'why', 'how', 'all', 'any', 'each', 'few', 'more', 'most', 'other', 'some', 'such', 'no', 'nor', 'only', 'own', 'same', 'so', 'than', 'too', 'very', 's', 't', 'can', 'will', 'just', 'don', 'should', 'now'];
        $this->tokens = array_filter($this->tokens, function($token) use ($stop_words) {
            return !in_array($token, $stop_words);
        });
    }
}

class DataMutator {
    public $tokens;
    public $mutated_tokens = [];

    public function __construct($tokens) {
        $this->tokens = $tokens;
    }

    public function mutate() {
        foreach ($this->tokens as $token) {
            if (rand(0, 1) == 1) {
                $this->mutated_tokens[] = strrev($token);
            } else {
                $this->mutated_tokens[] = $token;
            }
        }
    }
}

function main() {
    $text = 'Document parsing and lexical tokenization are important for natural language processing tasks.';
    $parser = new DocumentParser($text);
    $parser->tokenize();
    $parser->filter_tokens();
    $mutator = new DataMutator($parser->tokens);
    $mutator->mutate();
    print_r($mutator->mutated_tokens);
}

main();