<?php

function tokenize($text) {
    if (!$text) {
        return [];
    }
    list($first, ...$rest) = explode(' ', $text, 2);
    return [$first] + tokenize(implode(' ', $rest));
}

function vectorize($tokens, $vec, $index = 0) {
    if ($index == count($tokens)) {
        return $vec;
    }
    if (!isset($vec[$tokens[$index]])) {
        $vec[$tokens[$index]] = 0;
    }
    $vec[$tokens[$index]] += 1;
    return vectorize($tokens, $vec, $index + 1);
}

function main() {
    $text = 'hello world hello';
    $tokens = tokenize($text);
    $vec = [];
    $result = vectorize($tokens, $vec);
    print_r($result);
}

main();

?>