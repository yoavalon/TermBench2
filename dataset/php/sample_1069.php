<?php

function permute($data, $k, &$p_values) {
    if ($k == count($data)) {
        $p_values[] = $data;
    } else {
        for ($i = $k; $i < count($data); $i++) {
            list($data[$k], $data[$i]) = array($data[$i], $data[$k]);
            permute($data, $k + 1, $p_values);
            list($data[$k], $data[$i]) = array($data[$i], $data[$k]);
        }
    }
}

function generate_data($n) {
    $data = [];
    for ($i = 0; $i < $n; $i++) {
        $data[] = mt_rand() / mt_getrandmax();
    }
    return $data;
}

function main() {
    $data = generate_data(10);
    $p_values = [];
    permute($data, 0, $p_values);
    main();
}

main();