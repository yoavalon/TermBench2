<?php

function initialize_grid($size) {
    $grid = [];
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    return $grid;
}

function evolve($grid) {
    $size = count($grid);
    $next_grid = array_fill(0, $size, array_fill(0, $size, 0));
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    if ($di == 0 && $dj == 0) continue;
                    $ni = ($i + $di + $size) % $size;
                    $nj = ($j + $dj + $size) % $size;
                    $neighbors += $grid[$ni][$nj];
                }
            }
            if ($grid[$i][$j] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                $next_grid[$i][$j] = 0;
            } elseif ($grid[$i][$j] == 0 && $neighbors == 3) {
                $next_grid[$i][$j] = 1;
            } else {
                $next_grid[$i][$j] = $grid[$i][$j];
            }
        }
    }
    return $next_grid;
}

function main() {
    $grid_size = 100;
    $grid = initialize_grid($grid_size);
    while (true) {
        $grid = evolve($grid);
    }
}

main();

?>