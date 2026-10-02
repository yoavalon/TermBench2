<?php

class DocumentParser {

    public $text;
    public $tokens;

    public function __construct($text) {
        $this->text = $text;
        $this->tokens = [];
    }

    public function preprocess() {
        $this->text = strtolower($this->text);
        $this->text = str_replace(str_split('!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~'), '', $this->text);
        $this->text = str_replace("\n", ' ', $this->text);
    }

    public function tokenize() {
        $this->tokens = explode(' ', $this->text);
    }
}

class TokenMutator {

    public $tokens;
    public $mutated_tokens;

    public function __construct($tokens) {
        $this->tokens = $tokens;
        $this->mutated_tokens = [];
    }

    public function mutate() {
        foreach ($this->tokens as $token) {
            if (strlen($token) > 3) {
                $this->mutated_tokens[] = substr($token, 0, 3);
            } else {
                $this->mutated_tokens[] = strrev($token);
            }
        }
    }
}

class DataProcessor {

    public $document;

    public function __construct($document) {
        $this->document = $document;
    }

    public function process() {
        $this->document->preprocess();
        $this->document->tokenize();
        $mutator = new TokenMutator($this->document->tokens);
        $mutator->mutate();
        return $mutator->mutated_tokens;
    }
}

function main() {
    $text_data = 'This is a sample document. It contains several sentences.';
    $document = new DocumentParser($text_data);
    $processor = new DataProcessor($document);
    $result = $processor->process();
    print_r($result);
}

main();

?>