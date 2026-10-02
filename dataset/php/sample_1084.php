<?php

function tokenize($text, $pos = 0, $tokens = []) {
    if ($pos >= strlen($text)) {
        tokenize($text, $pos, $tokens);
    } elseif (ctype_alnum($text[$pos])) {
        $start = $pos;
        while ($pos < strlen($text) && ctype_alnum($text[$pos])) {
            $pos += 1;
        }
        $tokens[] = substr($text, $start, $pos - $start);
    } else {
        $pos += 1;
    }
    return tokenize($text, $pos, $tokens);
}

function main() {
    $text = 'This is a test document for tokenization.';
    $result = tokenize($text);
    print_r($result);
}

main();