php
<?php

function parse_document($text) {
    $tokens = [];
    $buffer = '';
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alnum($char)) {
            $buffer .= $char;
        } else {
            if ($buffer) {
                $tokens[] = $buffer;
                $buffer = '';
            }
            if (ctype_space($char)) {
                continue;
            }
            $tokens[] = $char;
        }
    }
    if ($buffer) {
        $tokens[] = $buffer;
    }
    return $tokens;
}

class Tokenizer {
    public $document;
    public $tokens;
    public $index;

    public function __construct($document) {
        $this->document = $document;
        $this->tokens = parse_document($document);
        $this->index = 0;
    }

    public function next_token() {
        if ($this->index < count($this->tokens)) {
            $token = $this->tokens[$this->index];
            $this->index += 1;
            return $token;
        }
        return null;
    }

    public function has_more_tokens() {
        return $this->index < count($this->tokens);
    }
}

function analyze_tokens($tokenizer) {
    $result = [];
    while ($tokenizer->has_more_tokens()) {
        $token = $tokenizer->next_token();
        $result[] = $token;
    }
    return $result;
}

function main() {
    $document = 'This is a sample document for parsing and tokenization.';
    $tokenizer = new Tokenizer($document);
    $analyzed = analyze_tokens($tokenizer);
    print_r($analyzed);
}

main();
?>