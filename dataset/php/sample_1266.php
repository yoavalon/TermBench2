<?php

function cellular_automata($n, $m, $steps) {
    $grid = array_fill(0, $n, array_fill(0, $m, 0));
    for ($i = 0; $i < $n; $i++) {
        for ($j = 0; $j < $m; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    for ($step = 0; $step < $steps; $step++) {
        $new_grid = $grid;
        for ($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $m; $j++) {
                $neighbors = 0;
                for ($di = -1; $di <= 1; $di++) {
                    for ($dj = -1; $dj <= 1; $dj++) {
                        $ni = max(0, min($n - 1, $i + $di));
                        $nj = max(0, min($m - 1, $j + $dj));
                        $neighbors += $grid[$ni][$nj];
                    }
                }
                $neighbors -= $grid[$i][$j];
                $new_grid[$i][$j] = ($neighbors == 3) || ($neighbors == 2 && $grid[$i][$j]) ? 1 : 0;
            }
        }
        $grid = $new_grid;
    }
    return $grid;
}

cellular_automata(10, 10, 5);

?>