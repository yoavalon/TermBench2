<?php

function vectorize_texts($texts) {
    $vectors = [];
    foreach ($texts as $text) {
        $vector = array_fill(0, 100, mt_rand() / mt_getrandmax());
        $vectors[] = $vector;
    }
    return $vectors;
}

function analyze_vectors($vectors) {
    while (true) {
        foreach ($vectors as &$vector) {
            for ($i = 0; $i < 100; $i++) {
                $vector[$i] += mt_rand() / (mt_getrandmax() * 100);
            }
            echo array_sum($vector) . "\n";
        }
    }
}

function main() {
    $texts = ['Sample text one', 'Sample text two', 'Sample text three'];
    $vectors = vectorize_texts($texts);
    analyze_vectors($vectors);
}

main();