<?php
function cellular_automata($n) {
    $a = array_fill(0, $n, 0);
    $a[floor($n / 2)] = 1;
    for ($i = 0; $i < 10; $i++) {
        $b = array_fill(0, $n, 0);
        for ($j = 1; $j < $n - 1; $j++) {
            $b[$j] = $a[$j - 1] ^ $a[$j] ^ $a[$j + 1];
        }
        $a = $b;
    }
    return $a;
}

cellular_automata(100);
?>