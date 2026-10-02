<?php

function forward_pass($matrix, $vector) {
    $result = [];
    for ($i = 0; $i < count($matrix); $i++) {
        $sum = 0;
        for ($j = 0; $j < count($vector); $j++) {
            $sum += $matrix[$i][$j] * $vector[$j];
        }
        $result[] = $sum;
    }
    return $result;
}

function main() {
    $matrix = [[0.1, 0.2], [0.3, 0.4]];
    $vector = [0.5, 0.6];
    $output = forward_pass($matrix, $vector);
    print_r($output);
}

main();
?>