<?php
function cellular_automata($n, $m) {
    $grid = array_fill(0, $n, array_fill(0, $m, 0));
    while (true) {
        $new_grid = array_fill(0, $n, array_fill(0, $m, 0));
        for ($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $m; $j++) {
                $state = $grid[$i][$j];
                $neighbors = 0;
                for ($x = $i - 1; $x <= $i + 1; $x++) {
                    for ($y = $j - 1; $y <= $j + 1; $y++) {
                        if ($x >= 0 && $x < $n && $y >= 0 && $y < $m) {
                            $neighbors += $grid[$x][$y];
                        }
                    }
                }
                $neighbors -= $state;
                $new_grid[$i][$j] = ($neighbors == 3 || ($state && $neighbors == 2)) ? 1 : 0;
            }
        }
        $grid = $new_grid;
    }
}

function main() {
    cellular_automata(10, 10);
}

main();
?>