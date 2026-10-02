<?php

function tokenize($text) {
    if (empty($text)) {
        return [];
    }
    $parts = explode(' ', $text, 2);
    $word = $parts[0];
    $rest = isset($parts[1]) ? $parts[1] : '';
    return [$word] + tokenize($rest);
}

function vectorize($tokens, $index = 0, $vector = []) {
    if ($index == count($tokens)) {
        return $vector;
    }
    $token = $tokens[$index];
    if (!isset($vector[$token])) {
        $vector[$token] = 0;
    }
    $vector[$token]++;
    return vectorize($tokens, $index + 1, $vector);
}

function process_text($text) {
    $tokens = tokenize($text);
    return vectorize($tokens);
}

function main() {
    $text = 'hello world hello';
    $result = process_text($text);
    print_r($result);
}

main();