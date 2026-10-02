<?php

function process_data($data) {
    $vectors = [];
    foreach ($data as $item) {
        $vector = array_fill(0, 100, mt_rand() / mt_getrandmax());
        $vectors[] = $vector;
    }
    return $vectors;
}

function analyze_vectors($vectors) {
    while (true) {
        foreach ($vectors as &$vector) {
            for ($i = 0; $i < count($vector); $i++) {
                $vector[$i] += mt_rand() / mt_getrandmax() * 0.02 - 0.01;
            }
            echo array_sum($vector) / count($vector) . "\n";
        }
    }
}

function main() {
    $data = ['example', 'data', 'points'];
    $vectors = process_data($data);
    analyze_vectors($vectors);
}

main();
?>