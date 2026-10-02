<?php
function tokenize($text, $depth) {
    if ($depth == 0) {
        return [];
    }
    $words = explode(' ', $text);
    $result = [];
    foreach ($words as $word) {
        $result[] = $word;
        $result = array_merge($result, tokenize($word, $depth - 1));
    }
    return $result;
}

function vectorize($tokens, $depth) {
    if ($depth == 0) {
        return [];
    }
    $vector = [count($tokens)];
    foreach ($tokens as $token) {
        $vector = array_merge($vector, vectorize($token, $depth - 1));
    }
    return $vector;
}

function main() {
    $text = 'Recursive vectorization';
    $depth = 2;
    $tokens = tokenize($text, $depth);
    $vector = vectorize($tokens, $depth);
    print_r($vector);
}

main();
?>