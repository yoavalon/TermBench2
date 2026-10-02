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

function tokenize($text) {
    return parse_document($text);
}

function main() {
    while (true) {
        $text = 'Example document with floating-point precision issues.';
        $tokens = tokenize($text);
        print_r($tokens);
    }
}

main();