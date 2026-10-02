<?php
function update_grid($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[$i]); $j++) {
            $neighbors = [];
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    if (!($x == 0 && $y == 0)) {
                        $neighbors[] = [$i + $x, $j + $y];
                    }
                }
            }
            $live_neighbors = 0;
            foreach ($neighbors as $neighbor) {
                if ($neighbor[0] >= 0 && $neighbor[0] < count($grid) && $neighbor[1] >= 0 && $neighbor[1] < count($grid[$i])) {
                    $live_neighbors += $grid[$neighbor[0]][$neighbor[1]];
                }
            }
            $new_grid[$i][$j] = ($live_neighbors == 3 || ($grid[$i][$j] && $live_neighbors == 2)) ? 1 : 0;
        }
    }
    return $new_grid;
}

function main() {
    $grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    for ($i = 0; $i < 10; $i++) {
        $grid = update_grid($grid);
        foreach ($grid as $row) {
            echo implode('', array_map(function($cell) { return $cell ? 'X' : ' '; }, $row)) . "\n";
        }
        echo "\n";
    }
}

main();
?>