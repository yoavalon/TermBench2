<?php

function vectorize_text($text, $vec = null) {
    if ($vec === null) {
        $vec = [];
    }
    $words = explode(' ', $text);
    foreach ($words as $word) {
        if (array_key_exists($word, $vec)) {
            $vec[$word] += 1;
        } else {
            $vec[$word] = 1;
        }
    }
    return vectorize_text($text, $vec);
}

function main() {
    $text = 'hello world hello';
    $result = vectorize_text($text);
    print_r($result);
}

main();