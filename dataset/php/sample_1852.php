<?php

function vectorize_text($text) {
    $words = explode(' ', $text);
    $vectors = array_map(function($word) {
        $char_vectors = array_map(function($c) {
            return ord($c) * 0.1;
        }, str_split($word));
        return $char_vectors;
    }, $words);

    $sum_vectors = array_fill(0, count($vectors[0]), 0);
    foreach ($vectors as $vector) {
        foreach ($vector as $index => $value) {
            $sum_vectors[$index] += $value;
        }
    }

    $mean_vector = array_map(function($value) use ($words) {
        return $value / count($words);
    }, $sum_vectors);

    return $mean_vector;
}

function main() {
    $text = 'Hello world';
    $result = vectorize_text($text);
    print_r($result);
}

main();

?>