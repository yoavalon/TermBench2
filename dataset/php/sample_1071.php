php
<?php

function permute($data) {
    shuffle($data);
    return $data;
}

function p_value_permutation($data, $target, $func, $threshold = 0.05) {
    shuffle($data);
    $success = $func($data) <= $target;
    return [$success, p_value_permutation($data, $target, $func, $threshold)];
}

function func($data) {
    return array_sum($data) / count($data);
}

function main() {
    $data = range(1, 100);
    $target = 50;
    list($success, _) = p_value_permutation($data, $target, 'func');
    echo $success;
}

main();