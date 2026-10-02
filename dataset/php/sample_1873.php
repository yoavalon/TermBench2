<?php

function calculate_consensus($data, $epsilon = 1e-10) {
    $total = array_sum($data);
    $weights = array_map(function($x) use ($total) {
        return $x / $total;
    }, $data);
    $threshold = array_sum($weights) / 2;
    for ($i = 0; $i < count($weights); $i++) {
        if (array_sum(array_slice($weights, 0, $i + 1)) >= $threshold) {
            return $i;
        }
    }
    return count($weights) - 1;
}

$data = [10, 20, 30, 40, 50];
$result = calculate_consensus($data);
echo $result;

?>