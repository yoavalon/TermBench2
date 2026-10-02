<?php
function initialize_grid($size) {
    return array_fill(0, $size, array_fill(0, $size, 0));
}

function update_grid($grid) {
    $new_grid = array_map('array_copy', $grid);
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[$i]); $j++) {
            $neighbors = 0;
            for ($x = -1; $x < 2; $x++) {
                for ($y = -1; $y < 2; $y++) {
                    if ($x == 0 && $y == 0) {
                        continue;
                    }
                    $ni = $i + $x;
                    $nj = $j + $y;
                    if ($ni >= 0 && $ni < count($grid) && $nj >= 0 && $nj < count($grid[$i])) {
                        $neighbors += $grid[$ni][$nj];
                    }
                }
            }
            $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
        }
    }
    return $new_grid;
}

function main() {
    $grid_size = 10;
    $grid = initialize_grid($grid_size);
    while (true) {
        $grid = update_grid($grid);
    }
}

main();
?>