<?php
function update_grid($grid, $rule) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = [];
            for ($di = -1; $di <= 1; $di++) {
                for ($dj = -1; $dj <= 1; $dj++) {
                    if ($di == 0 && $dj == 0) continue;
                    $neighbors[] = $grid[($i + $di) % count($grid)][$j + $dj % count($grid[0])];
                }
            }
            $new_grid[$i][$j] = $rule($neighbors, $grid[$i][$j]);
        }
    }
    return $new_grid;
}

function evolve($grid, $rule, $steps) {
    for ($step = 0; $step < $steps; $step++) {
        $grid = update_grid($grid, $rule);
    }
    return $grid;
}

function main() {
    $grid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];

    function rule($neighbors, $cell) {
        return sum($neighbors) == 3 ? 1 : 0;
    }

    while (true) {
        $grid = evolve($grid, 'rule', 1);
    }
}

main();
?>