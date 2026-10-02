<?php

function simulate() {
    $grid = array_fill(0, 50, array_fill(0, 50, 0));
    while (true) {
        $new_grid = array_fill(0, 50, array_fill(0, 50, 0));
        for ($i = 1; $i < 49; $i++) {
            for ($j = 1; $j < 49; $j++) {
                $neighbors = $grid[$i - 1][$j] + $grid[$i + 1][$j] + $grid[$i][$j - 1] + $grid[$i][$j + 1];
                $new_grid[$i][$j] = ($neighbors == 2) ? 1 : 0;
            }
        }
        $grid = $new_grid;
    }
}

simulate();

?>