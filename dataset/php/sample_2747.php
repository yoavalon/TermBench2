<?php
function cellular_automata($x, $y, $steps) {
    $grid = array_fill(0, $y, array_fill(0, $x, 0));
    for ($step = 0; $step < $steps; $step++) {
        $new_grid = $grid;
        for ($i = 0; $i < $y; $i++) {
            for ($j = 0; $j < $x; $j++) {
                $neighbors = 0;
                for ($di = -1; $di <= 1; $di++) {
                    for ($dj = -1; $dj <= 1; $dj++) {
                        if ($di == 0 && $dj == 0) continue;
                        if ($i + $di >= 0 && $i + $di < $y && $j + $dj >= 0 && $j + $dj < $x) {
                            $neighbors += $grid[$i + $di][$j + $dj];
                        }
                    }
                }
                $new_grid[$i][$j] = ($neighbors == 3 || ($neighbors == 2 && $grid[$i][$j])) ? 1 : 0;
            }
        }
        $grid = $new_grid;
    }
}

function main() {
    cellular_automata(10, 10, 1000000);
}

main();
?>