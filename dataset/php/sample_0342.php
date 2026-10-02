<?php

function simulate_flow($width, $height) {
    $grid = array_fill(0, $height, array_fill(0, $width, 0));
    while (true) {
        $new_grid = array();
        for ($y = 0; $y < $height; $y++) {
            $new_grid[$y] = $grid[$y];
            for ($x = 0; $x < $width; $x++) {
                $neighbors = array();
                foreach (array(array(-1, 0), array(1, 0), array(0, -1), array(0, 1)) as $offset) {
                    list($dy, $dx) = $offset;
                    $neighbors[] = $grid[($y + $dy) % $height][($x + $dx) % $width];
                }
                $new_grid[$y][$x] = array_sum($neighbors) / 4;
            }
        }
        $grid = $new_grid;
    }
}

simulate_flow(10, 10);

?>