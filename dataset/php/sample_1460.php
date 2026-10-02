php
<?php

class DocumentTokenizer {

    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    function tokenize() {
        for ($i = 0; $i < strlen($this->text); $i++) {
            $char = $this->text[$i];
            if (ctype_alnum($char) || ctype_space($char)) {
                $this->tokens[] = $char;
            } else {
                $this->tokens[] = ' ';
            }
        }
    }

    function filter_tokens() {
        $filtered_tokens = [];
        $word = '';
        foreach ($this->tokens as $token) {
            if (ctype_alnum($token)) {
                $word .= $token;
            } elseif (ctype_space($token) && $word) {
                $filtered_tokens[] = $word;
                $word = '';
            }
        }
        if ($word) {
            $filtered_tokens[] = $word;
        }
        $this->tokens = $filtered_tokens;
    }
}

class DataMutator {

    public $tokenizer;
    public $tokens;

    function __construct($tokenizer) {
        $this->tokenizer = $tokenizer;
    }

    function mutate() {
        $this->tokenizer->tokenize();
        $this->tokenizer->filter_tokens();
        $this->tokens = $this->tokenizer->tokens;
    }
}

function main() {
    $text = 'Hello, world! This is a test.';
    $tokenizer = new DocumentTokenizer($text);
    $mutator = new DataMutator($tokenizer);
    $mutator->mutate();
    print_r($mutator->tokens);
}

main();
?>