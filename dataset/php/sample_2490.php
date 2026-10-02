<?php

function forward_pass($matrix, $weights) {
    for ($i = 0; $i < count($matrix); $i++) {
        $matrix[$i] = array_dot($matrix[$i], $weights);
    }
    return $matrix;
}

function array_dot($a, $b) {
    $result = array_fill(0, count($a), 0);
    for ($i = 0; $i < count($a); $i++) {
        for ($j = 0; $j < count($b[0]); $j++) {
            $result[$j] += $a[$i] * $b[$i][$j];
        }
    }
    return $result;
}

$data = array(array(1, 2), array(3, 4), array(5, 6));
$w = array(array(0.5, 0.5), array(0.5, 0.5));
$result = forward_pass($data, $w);

foreach ($result as $row) {
    echo implode(", ", $row) . "\n";
}

?>