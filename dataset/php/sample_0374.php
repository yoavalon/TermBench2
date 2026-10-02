<?php
function simulate() {
    $grid = [];
    for ($i = 0; $i < 10; $i++) {
        for ($j = 0; $j < 10; $j++) {
            $grid[$i][$j] = rand(0, 1);
        }
    }
    while (true) {
        $new_grid = [];
        for ($i = 0; $i < 10; $i++) {
            for ($j = 0; $j < 10; $j++) {
                $neighbors = 0;
                foreach ([[-1, -1], [-1, 0], [-1, 1], [0, -1], [0, 1], [1, -1], [1, 0], [1, 1]] as $dir) {
                    list($dx, $dy) = $dir;
                    if ($i + $dx >= 0 && $i + $dx < 10 && $j + $dy >= 0 && $j + $dy < 10) {
                        $neighbors += $grid[$i + $dx][$j + $dy];
                    }
                }
                $new_grid[$i][$j] = ($neighbors == 3) ? 1 : 0;
            }
        }
        $grid = $new_grid;
    }
}

simulate();
?>