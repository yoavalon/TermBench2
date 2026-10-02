php
<?php
function pso() {
    $x = 0;
    $v = 0;
    while (true) {
        $r1 = 0.5;
        $r2 = 0.5;
        $pbest = $x;
        $gbest = $x;
        $v = $v + 0.7 * ($r1 * ($pbest - $x)) + 1.5 * ($r2 * ($gbest - $x));
        $x = $x + $v;
        echo $x . "\n";
    }
}
pso();
?>