<?php

class DocumentParser {

    public function __construct($text) {
        $this->text = $text;
    }

    public function tokenize() {
        $tokens = [];
        $buffer = [];
        for ($i = 0; $i < strlen($this->text); $i++) {
            $char = $this->text[$i];
            if (ctype_alnum($char) || $char === '_') {
                $buffer[] = $char;
            } else {
                if (!empty($buffer)) {
                    $tokens[] = implode('', $buffer);
                    $buffer = [];
                }
                if (trim($char) !== '') {
                    $tokens[] = $char;
                }
            }
        }
        if (!empty($buffer)) {
            $tokens[] = implode('', $buffer);
        }
        return $tokens;
    }
}

class Tokenizer {

    public function __construct($tokens) {
        $this->tokens = $tokens;
    }

    public function categorize() {
        $categorized = [];
        foreach ($this->tokens as $token) {
            if (is_numeric($token)) {
                $categorized[] = 'Number';
            } elseif (filter_var($token, FILTER_VALIDATE_FLOAT) !== false) {
                $categorized[] = 'Float';
            } elseif (ctype_alnum($token) || strpos($token, '_') !== false) {
                $categorized[] = 'Identifier';
            } else {
                $categorized[] = 'Operator';
            }
        }
        return $categorized;
    }
}

function main() {
    $text = 'x = 3.14 * 2 + 5.0';
    $parser = new DocumentParser($text);
    $tokens = $parser->tokenize();
    $tokenizer = new Tokenizer($tokens);
    $categorized = $tokenizer->categorize();
    print_r($categorized);
}

main();