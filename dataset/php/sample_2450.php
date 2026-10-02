<?php
function simulate_cells($rows, $cols, $steps) {
    $grid = array_fill(0, $rows, array_fill(0, $cols, 0));
    for ($t = 0; $t < $steps; $t++) {
        $new_grid = array_fill(0, $rows, array_fill(0, $cols, 0));
        for ($i = 0; $i < $rows; $i++) {
            for ($j = 0; $j < $cols; $j++) {
                $neighbors = 0;
                for ($x = max(0, $i - 1); $x < min($rows, $i + 2); $x++) {
                    for ($y = max(0, $j - 1); $y < min($cols, $j + 2); $y++) {
                        if ($x != $i || $y != $j) {
                            $neighbors += $grid[$x][$y];
                        }
                    }
                }
                if ($neighbors == 3 || ($grid[$i][$j] && $neighbors == 2)) {
                    $new_grid[$i][$j] = 1;
                }
            }
        }
        $grid = $new_grid;
    }
    return $grid;
}

simulate_cells(10, 10, 5);
?>