<?php

function optimize_supply_chain($data) {
    $demand = array_map(function() {
        return rand(100, 500);
    }, range(0, count($data) - 1));

    $supply = array_map(function() {
        return rand(100, 500);
    }, range(0, count($data) - 1));

    $mutations = array_map(function($d, $s) {
        return $d > $s ? $d - $s : 0;
    }, $demand, $supply);

    return $mutations;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $data = range(0, 9);
    $result = optimize_supply_chain($data);
    print_r($result);
}