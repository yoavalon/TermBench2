<?php

function vectorize_text($text, $vec, $index) {
    if ($index == strlen($text)) {
        return $vec;
    }
    $char = strtolower($text[$index]);
    if ('a' <= $char && $char <= 'z') {
        $vec[ord($char) - ord('a')]++;
    }
    return vectorize_text($text, $vec, $index + 1);
}

function main() {
    $text = 'Hello, World!';
    $vec = array_fill(0, 26, 0);
    $result = vectorize_text($text, $vec, 0);
    print_r($result);
}

main();