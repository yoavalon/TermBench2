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

function process_text($text) {
    $vocab = ['hello' => 0, 'world' => 1, 'python' => 2];
    $tokens = tokenize($text);
    $vector = vectorize($tokens, $vocab);
    return $vector;
}

function main() {
    $text = 'Hello world, hello Python!';
    $result = process_text($text);
    print_r($result);
}

main();