<?php

function vectorize_text($text) {
    $words = explode(' ', $text);
    $vocab = array_flip(array_unique($words));
    $vectors = array_fill(0, count($words), array_fill(0, count($vocab), 0));
    foreach ($words as $i => $word) {
        $vectors[$i][$vocab[$word]] = 1;
    }
    return $vectors;
}

function analyze_sequence($sequence) {
    $processed = [];
    foreach ($sequence as $item) {
        if (is_string($item)) {
            $processed[] = vectorize_text($item);
        }
    }
    $result = [];
    foreach ($processed as $matrix) {
        $result = array_merge($result, $matrix);
    }
    return $result;
}

function main() {
    $data = ['hello world', 'data science', 'hello universe'];
    $result = analyze_sequence($data);
    print_r($result);
}

main();
?>