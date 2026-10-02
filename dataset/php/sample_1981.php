php
<?php
function update_state($grid) {
    $new_grid = array_fill(0, count($grid), array_fill(0, count($grid[0]), 0.0));
    for ($i = 0; $i < count($grid); $i++) {
        for ($j = 0; $j < count($grid[0]); $j++) {
            $neighbors = 0;
            for ($x = -1; $x <= 1; $x++) {
                for ($y = -1; $y <= 1; $y++) {
                    if ($x == 0 && $y == 0) {
                        continue;
                    }
                    $ni = $i + $x;
                    $nj = $j + $y;
                    if ($ni >= 0 && $ni < count($grid) && $nj >= 0 && $nj < count($grid[0])) {
                        $neighbors += $grid[$ni][$nj];
                    }
                }
            }
            $new_grid[$i][$j] = $neighbors / 9.0;
        }
    }
    return $new_grid;
}

function run_simulation($steps, $size) {
    $grid = array_fill(0, $size, array_fill(0, $size, 0.0));
    for ($i = 0; $i < $size; $i++) {
        $grid[$i][$i] = 1.0;
    }
    for ($step = 0; $step < $steps; $step++) {
        $grid = update_state($grid);
    }
    return $grid;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = run_simulation(10, 5);
    foreach ($result as $row) {
        echo implode(' ', $row) . "\n";
    }
}
?>