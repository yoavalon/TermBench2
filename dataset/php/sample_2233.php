<?php
function update_state($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = array(
                $grid[($i - 1 + count($grid)) % count($grid)][$j % count($grid[0])],
                $grid[($i - 1 + count($grid)) % count($grid)][$j],
                $grid[($i - 1 + count($grid)) % count($grid)][$j % count($grid[0]) + 1],
                $grid[$i % count($grid)][$j % count($grid[0]) - 1],
                $grid[$i % count($grid)][$j % count($grid[0]) + 1],
                $grid[($i + 1) % count($grid)][$j % count($grid[0]) - 1],
                $grid[($i + 1) % count($grid)][$j],
                $grid[($i + 1) % count($grid)][$j % count($grid[0]) + 1]
            );
            $live_neighbors = array_sum($neighbors);
            if ($grid[$i][$j] == 1) {
                if ($live_neighbors < 2 || $live_neighbors > 3) {
                    $new_grid[$i][$j] = 0;
                } else {
                    $new_grid[$i][$j] = 1;
                }
            } elseif ($live_neighbors == 3) {
                $new_grid[$i][$j] = 1;
            } else {
                $new_grid[$i][$j] = 0;
            }
        }
    }
    return $new_grid;
}

function main() {
    $grid = array(
        array(0, 1, 0, 0, 0),
        array(0, 0, 1, 0, 0),
        array(0, 1, 1, 1, 0),
        array(0, 0, 0, 0, 0),
        array(0, 0, 0, 0, 0)
    );
    while (true) {
        $grid = update_state($grid);
        foreach ($grid as $row) {
            echo implode(' ', $row) . "\n";
        }
        echo "\n";
    }
}

main();
?>