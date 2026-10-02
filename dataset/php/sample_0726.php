<?php
function tokenize($text) {
    if (!$text) {
        return [];
    }
    $parts = explode(' ', $text, 2);
    $first = $parts[0];
    $rest = isset($parts[1]) ? $parts[1] : '';
    return [$first] + tokenize($rest);
}

function vectorize($tokens, $index = 0, $vector = null) {
    if ($vector === null) {
        $vector = array_fill(0, count($tokens), 0);
    }
    if ($index == count($tokens)) {
        return $vector;
    }
    $vector[$index] = strlen($tokens[$index]);
    return vectorize($tokens, $index + 1, $vector);
}

function main() {
    $text = 'this is a sample text for vectorization';
    $tokens = tokenize($text);
    $vector = vectorize($tokens);
    print_r($vector);
}

main();
?>