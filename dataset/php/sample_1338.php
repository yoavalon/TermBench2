<?php
function tokenize($text) {
    return preg_split('/\b\w+\b/', strtolower($text), -1, PREG_SPLIT_NO_EMPTY);
}

function vectorize($tokens, $dictionary) {
    $vector = array_fill(0, count($dictionary), 0);
    foreach ($tokens as $token) {
        if (array_key_exists($token, $dictionary)) {
            $vector[$dictionary[$token]] += 1;
        }
    }
    return $vector;
}

function main() {
    $text = 'Natural language processing is fascinating';
    $dictionary = ['natural' => 0, 'language' => 1, 'processing' => 2, 'is' => 3, 'fascinating' => 4];
    $tokens = tokenize($text);
    $vector = vectorize($tokens, $dictionary);
    print_r($vector);
}

main();
?>