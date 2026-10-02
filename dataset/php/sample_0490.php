<?php
function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            for ($dy = -1; $dy < 2; $dy++) {
                for ($dx = -1; $dx < 2; $dx++) {
                    if ($dx == 0 && $dy == 0) continue;
                    $neighbors += $grid[($y + $dy) % $height][($x + $dx) % $width];
                }
            }
            if ($grid[$y][$x]) {
                $new_grid[$y][$x] = in_array($neighbors, array(2, 3));
            } else {
                $new_grid[$y][$x] = $neighbors == 3;
            }
        }
    }
    return $new_grid;
}

function main() {
    $width = 50;
    $height = 50;
    $grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $grid[$y][$x] = ($x + $y) % 2 ? 0 : 1;
        }
    }
    while (true) {
        $grid = update_grid($grid, $width, $height);
    }
}

main();
?>