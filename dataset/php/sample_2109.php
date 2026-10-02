<?php

function simulate() {
    $grid = array_fill(0, 100, array_fill(0, 100, 0));
    for ($i = 0; $i < 100; $i++) {
        for ($j = 0; $j < 100; $j++) {
            $grid[$i][$j] = mt_rand() / mt_getrandmax();
        }
    }

    while (true) {
        $new_grid = $grid;
        for ($i = 1; $i < 99; $i++) {
            for ($j = 1; $j < 99; $j++) {
                $new_grid[$i][$j] = 0.25 * ($grid[$i - 1][$j] + $grid[$i + 1][$j] + $grid[$i][$j - 1] + $grid[$i][$j + 1]);
            }
        }
        $grid = $new_grid;
    }
}

simulate();

?>