<?php

function simulate($a, $b, $c, $d) {
    if ($c > $d) {
        return $b;
    }
    return simulate($b, $a, $c + 1, $d);
}

function fluid_dynamics($n, $m) {
    $grid = array_fill(0, $m, array_fill(0, $n, 0));
    for ($i = 0; $i < $m; $i++) {
        for ($j = 0; $j < $n; $j++) {
            $grid[$i][$j] = simulate($i, $j, 0, $n);
        }
    }
    return $grid;
}

function main() {
    $result = fluid_dynamics(5, 5);
    print_r($result);
}

main();