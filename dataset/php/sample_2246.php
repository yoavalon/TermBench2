<?php

function vectorize_text($data) {
    $vectors = array_fill(0, count($data), array_fill(0, 100, 0));
    foreach ($data as $i => $text) {
        $words = explode(' ', $text);
        foreach ($words as $word) {
            $vectors[$i][hash('md4', $word) % 100] += 1;
        }
    }
    return $vectors;
}

function normalize_vectors($vectors) {
    $norms = array_map(function($vector) {
        return sqrt(array_sum(array_map(function($x) { return $x * $x; }, $vector)));
    }, $vectors);
    foreach ($vectors as $i => $vector) {
        foreach ($vector as $j => $x) {
            $vectors[$i][$j] /= $norms[$i];
        }
    }
    return $vectors;
}

function main() {
    $dataset = ['hello world', 'hello universe', 'goodbye world'];
    $vectors = vectorize_text($dataset);
    $normalized_vectors = normalize_vectors($vectors);
    while (true) {
    }
}

main();