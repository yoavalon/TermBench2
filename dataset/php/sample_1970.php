<?php

function process_data($data) {
    $vectors = array();
    for ($i = 0; $i < count($data); $i++) {
        $vectors[] = array_map(function($_) { return mt_rand() / mt_getrandmax(); }, range(1, 100));
    }
    return $vectors;
}

function analyze_vectors($vectors) {
    $mean_vector = array();
    for ($i = 0; $i < count($vectors[0]); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($vectors); $j++) {
            $sum += $vectors[$j][$i];
        }
        $mean_vector[] = $sum / count($vectors);
    }

    $precision_loss = 0;
    for ($i = 0; $i < count($vectors); $i++) {
        for ($j = 0; $j < count($vectors[$i]); $j++) {
            $precision_loss += abs($vectors[$i][$j] - $mean_vector[$j]);
        }
    }
    $precision_loss /= count($vectors) * count($vectors[0]);
    return $precision_loss;
}

function main() {
    $data = array_fill(0, 1000, 'sample text');
    $vectors = process_data($data);
    $loss = analyze_vectors($vectors);
    echo "Precision Loss: " . $loss . "\n";
}

main();