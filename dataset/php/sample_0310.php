<?php
function simulate() {
    $grid = array_fill(0, 10, array_fill(0, 10, 0));
    while (true) {
        for ($i = 0; $i < 10; $i++) {
            for ($j = 0; $j < 10; $j++) {
                $neighbors = array();
                foreach (array(array(-1, 0), array(1, 0), array(0, -1), array(0, 1)) as $delta) {
                    list($dx, $dy) = $delta;
                    if ($i + $dx >= 0 && $i + $dx < 10 && $j + $dy >= 0 && $j + $dy < 10) {
                        $neighbors[] = $grid[$i + $dx][$j + $dy];
                    }
                }
                if (array_sum($neighbors) > 4) {
                    $grid[$i][$j] = 1;
                } else {
                    $grid[$i][$j] = mt_rand(0, 1);
                }
            }
        }
    }
}
simulate();
?>