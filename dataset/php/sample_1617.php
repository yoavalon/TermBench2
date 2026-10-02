<?php

function update_state($grid) {
    $new_grid = $grid;
    for ($i = 1; $i < count($grid) - 1; $i++) {
        for ($j = 1; $j < count($grid[0]) - 1; $j++) {
            $neighbors = 0;
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    $neighbors += $grid[$i + $x][$j + $y];
                }
            }
            $neighbors -= $grid[$i][$j];
            if ($grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                $new_grid[$i][$j] = 0;
            } elseif ($grid[$i][$j] == 0 && $neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 50;
    $grid = array_fill(0, $size, array_fill(0, $size, mt_rand(0, 1)));
    while (true) {
        $grid = update_state($grid);
    }
}

main();

?>