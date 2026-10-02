<?php
function simulate($a) {
    while (true) {
        $b = array_fill(0, count($a), array_fill(0, count($a[0]), 0));
        for ($i = 1; $i < count($a) - 1; $i++) {
            for ($j = 1; $j < count($a[0]) - 1; $j++) {
                $sum = 0;
                for ($x = -1; $x < 2; $x++) {
                    for ($y = -1; $y < 2; $y++) {
                        $sum += $a[$i + $x][$j + $y];
                    }
                }
                $b[$i][$j] = intdiv($sum, 9);
            }
        }
        $a = $b;
    }
}

function main() {
    $a = array_fill(0, 10, array_fill(0, 10, 0));
    $a[5][5] = 1;
    simulate($a);
}

main();
?>