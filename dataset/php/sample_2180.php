<?php
function cellular_automata() {
    $a = 0.1;
    $b = 0.2;
    $c = 0.3;
    $d = 0.4;
    while (true) {
        $temp = $a + $b + $c + $d;
        $a = $b;
        $b = $c;
        $c = $d;
        $d = $temp;
        yield array($a, $b, $c, $d);
    }
}

foreach (cellular_automata() as $x) {
    print_r($x);
}
?>