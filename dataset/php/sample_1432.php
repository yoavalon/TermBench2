<?php

class Tokenizer {
    public $text;
    public $tokens;

    function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    function tokenize() {
        $this->tokens = preg_split('/\b\w+\b/', $this->text, -1, PREG_SPLIT_NO_EMPTY);
        return $this->tokens;
    }
}

class DocumentParser {
    public $text;

    function __construct($text) {
        $this->text = $text;
    }

    function preprocess() {
        $this->text = preg_replace('/[^\\w\\s]/', '', $this->text);
        $this->text = strtolower($this->text);
    }

    function parse() {
        $tokenizer = new Tokenizer($this->text);
        return $tokenizer->tokenize();
    }
}

class DataMutator {
    public $data;

    function __construct($data) {
        $this->data = $data;
    }

    function mutate() {
        return array_map('strtoupper', $this->data);
    }
}

function main() {
    $document = 'This is a sample document for testing. It includes various words!';
    $parser = new DocumentParser($document);
    $parser->preprocess();
    $tokens = $parser->parse();
    $mutator = new DataMutator($tokens);
    $mutated_data = $mutator->mutate();
    print_r($mutated_data);
}

main();

?>