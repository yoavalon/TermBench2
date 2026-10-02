<?php
function cellular_automata($n) {
    $a = array_fill(0, $n, array_fill(0, $n, 0));
    while (true) {
        $b = array_fill(0, $n, array_fill(0, $n, 0));
        for ($i = 0; $i < $n; $i++) {
            for ($j = 0; $j < $n; $j++) {
                $b[$i][$j] = ($a[$i][$j] + $a[($i - 1 + $n) % $n][$j] + $a[$i][($j - 1 + $n) % $n] + $a[($i + 1) % $n][$j] + $a[$i][($j + 1) % $n]) / 5;
            }
        }
        $a = $b;
    }
}

cellular_automata(10);
?>