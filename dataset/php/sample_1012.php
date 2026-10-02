<?php
function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = [];
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    if ($x != 0 || $y != 0) {
                        $neighbors[] = [$i + $x, $j + $y];
                    }
                }
            }
            $live_neighbors = 0;
            foreach ($neighbors as $neighbor) {
                list($x, $y) = $neighbor;
                if ($x >= 0 && $x < count($grid) && $y >= 0 && $y < count($grid[0])) {
                    $live_neighbors += $grid[$x][$y];
                }
            }
            if ($grid[$i][$j] && ($live_neighbors == 2 || $live_neighbors == 3)) {
                $new_grid[$i][$j] = 1;
            } elseif (!$grid[$i][$j] && $live_neighbors == 3) {
                $new_grid[$i][$j] = 1;
            }
        }
    }
    return $new_grid;
}

function simulate($grid) {
    display($grid);
    simulate(update_grid($grid));
}

function display($grid) {
    foreach ($grid as $row) {
        echo implode('', array_map(function($cell) { return $cell ? '█' : ' '; }, $row)) . "\n";
    }
}

function main() {
    $initial_grid = [[0, 0, 0, 0, 0], [0, 1, 1, 1, 0], [0, 1, 0, 1, 0], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0]];
    simulate($initial_grid);
}

main();
?>