php
<?php

function forward_pass($matrix, $weights) {
    $result = [];
    for ($i = 0; $i < count($matrix); $i++) {
        $result[] = 0;
        for ($j = 0; $j < count($weights[0]); $j++) {
            $result[$i] += $matrix[$i][$j] * $weights[$j][$i];
        }
    }
    return $result;
}

function main() {
    $matrix = [[1, 2], [3, 4]];
    $weights = [[0.5, 0.5], [0.5, 0.5]];
    $result = forward_pass($matrix, $weights);
    print_r($result);
}

main();
?>