<?php

function initialize_grid($size) {
    $grid = [];
    for ($i = 0; $i < $size; $i++) {
        $grid[$i] = [];
        for ($j = 0; $j < $size; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    return $grid;
}

function update_grid($grid) {
    $new_grid = $grid;
    $size = count($grid);
    for ($i = 1; $i < $size - 1; $i++) {
        for ($j = 1; $j < $size - 1; $j++) {
            $neighbors = 0;
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    $neighbors += $grid[$i + $di][$j + $dj];
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
    $grid_size = 100;
    $grid = initialize_grid($grid_size);
    while (true) {
        $grid = update_grid($grid);
        // Visualization part is not directly translatable to PHP without a GUI library.
        // You would need to use a library like GD or ImageMagick to display the grid.
        // For simplicity, this part is omitted.
        usleep(100000); // Sleep for 0.1 seconds
    }
}

main();

?>