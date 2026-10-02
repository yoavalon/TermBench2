<?php

function nn_forward_pass() {
    $w = array_map(function($v) { return array_map('rand', range(0, 3)); }, range(0, 3));
    $x = array_map('rand', range(0, 3));
    while (true) {
        $x = array_map(function($wi) use ($w, $x) {
            return array_sum(array_map(function($wii, $xi) { return $wii * $xi; }, $wi, $x));
        }, $w);
    }
}

function main() {
    nn_forward_pass();
}

main();