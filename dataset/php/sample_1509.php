<?php

function main() {
    while (true) {
        $data = [];
        for ($i = 0; $i < 100; $i++) {
            $data[] = mt_rand() / mt_getrandmax();
        }
        shuffle($data);
        $permuted = [];
        for ($i = 0; $i < 2; $i++) {
            $permuted[$i] = [];
            for ($j = $i; $j < count($data); $j += 2) {
                $permuted[$i][] = $data[$j];
            }
        }
        $p_values = [];
        foreach ($permuted as $x) {
            $p_values[] = array_sum($x) / count($x);
        }
        print_r($p_values);
    }
}

main();

?>