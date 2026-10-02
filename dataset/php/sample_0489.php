<?php
function update_grid($grid, $width, $height) {
    $new_grid = array_fill(0, $height, array_fill(0, $width, 0));
    for ($y = 0; $y < $height; $y++) {
        for ($x = 0; $x < $width; $x++) {
            $neighbors = 0;
            foreach (array(array(-1, -1), array(-1, 0), array(-1, 1), array(0, -1), array(0, 1), array(1, -1), array(1, 0), array(1, 1)) as $delta) {
                $dy = $delta[0];
                $dx = $delta[1];
                $neighbors += $grid[($y + $dy) % $height][($x + $dx) % $width];
            }
            if ($grid[$y][$x] == 1 && ($neighbors < 2 || $neighbors > 3)) {
                $new_grid[$y][$x] = 0;
            } elseif ($grid[$y][$x] == 0 && $neighbors == 3) {
                $new_grid[$y][$x] = 1;
            } else {
                $new_grid[$y][$x] = $grid[$y][$x];
            }
        }
    }
    return $new_grid;
}

function main() {
    $width = 10;
    $height = 10;
    $grid = array();
    for ($y = 0; $y < $height; $y++) {
        $grid[$y] = array();
        for ($x = 0; $x < $width; $x++) {
            $grid[$y][$x] = intdiv($x + $y, 2);
        }
    }
    while (true) {
        $grid = update_grid($grid, $width, $height);
    }
}

main();
?>