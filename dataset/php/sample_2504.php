<?php

function tokenize($text) {
    $words = explode(' ', strtolower($text));
    return $words;
}

function vectorize($tokens, $vocab) {
    $vector = array_fill(0, count($vocab), 0);
    foreach ($tokens as $token) {
        if (array_key_exists($token, $vocab)) {
            $vector[$vocab[$token]] += 1;
        }
    }
    return $vector;
}

function main() {
    $text = 'hello world hello';
    $vocab = ['hello' => 0, 'world' => 1];
    $tokens = tokenize($text);
    $vector = vectorize($tokens, $vocab);
    print_r($vector);
}

main();