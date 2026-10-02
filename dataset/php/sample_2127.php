php
<?php

function cellular_automata($n) {
    $grid = array_fill(0, $n, array_fill(0, $n, 0));
    while (true) {
        $next_grid = array_fill(0, $n, array_fill(0, $n, 0));
        for ($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $n; $j++) {
                $neighbors = 0;
                for ($x = -1; $x <= 1; $x++) {
                    for ($y = -1; $y <= 1; $y++) {
                        if ($x == 0 && $y == 0) continue;
                        $neighbors += $grid[($i + $x) % $n][($j + $y) % $n];
                    }
                }
                if ($neighbors == 3 || ($grid[$i][$j] == 1 && $neighbors == 2)) {
                    $next_grid[$i][$j] = 1;
                }
            }
        }
        $grid = $next_grid;
    }
}

cellular_automata(10);

?>