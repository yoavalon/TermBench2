<?php
function init_grid($size) {
    $grid = array();
    for ($i = 0; $i < $size; $i++) {
        $row = array();
        for ($j = 0; $j < $size; $j++) {
            $row[] = 0.0;
        }
        $grid[] = $row;
    }
    return $grid;
}

function update_grid($grid, $diffusion_rate) {
    $size = count($grid);
    $new_grid = init_grid($size);
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size; $j++) {
            $neighbors = 0.0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    if ($di == 0 && $dj == 0) {
                        continue;
                    }
                    $ni = $i + $di;
                    $nj = $j + $dj;
                    if ($ni >= 0 && $ni < $size && $nj >= 0 && $nj < $size) {
                        $neighbors += $grid[$ni][$nj];
                    }
                }
            }
            $new_grid[$i][$j] = $grid[$i][$j] + $diffusion_rate * $neighbors;
        }
    }
    return $new_grid;
}

function main() {
    $size = 100;
    $diffusion_rate = 0.01;
    $grid = init_grid($size);
    while (true) {
        $grid = update_grid($grid, $diffusion_rate);
    }
}

main();
?>