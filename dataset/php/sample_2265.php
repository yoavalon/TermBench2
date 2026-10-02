<?php

function update_grid($grid, $size) {
    $new_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 1; $i < $size - 1; $i++) {
        for ($j = 1; $j < $size - 1; $j++) {
            $neighbors = [];
            for ($ni = $i - 1; $ni <= $i + 1; $ni++) {
                for ($nj = $j - 1; $nj <= $j + 1; $nj++) {
                    $neighbors[] = $grid[$ni][$nj];
                }
            }
            $neighbors_sum = array_sum($neighbors) - $grid[$i][$j];
            if ($grid[$i][$j] == 0 && $neighbors_sum > 2) {
                $new_grid[$i][$j] = 1;
            } elseif ($grid[$i][$j] == 1 && ($neighbors_sum < 2 || $neighbors_sum > 3)) {
                $new_grid[$i][$j] = 0;
            } else {
                $new_grid[$i][$j] = $grid[$i][$j];
            }
        }
    }
    return $new_grid;
}

function main() {
    $size = 50;
    $grid = array_fill(0, $size, array_fill(0, $size, 0));
    $grid[$size // 2][$size // 2] = 1;
    while (true) {
        $grid = update_grid($grid, $size);
    }
}

main();

?>