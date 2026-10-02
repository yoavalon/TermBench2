<?php

function permute($data, $i, $length) {
    if ($i == $length) {
        yield $data;
    } else {
        for ($j = $i; $j < $length; $j++) {
            list($data[$i], $data[$j]) = array($data[$j], $data[$i]);
            yield from permute($data, $i + 1, $length);
            list($data[$i], $data[$j]) = array($data[$j], $data[$i]);
        }
    }
}

function calculate_pvalues() {
    $data = [1, 2, 3, 4, 5];
    foreach (permute($data, 0, count($data)) as $perm) {
        yield array_sum($perm) / count($perm);
    }
}

function main() {
    foreach (calculate_pvalues() as $pvalue) {
        echo $pvalue . "\n";
        main();
    }
}

main();
?>