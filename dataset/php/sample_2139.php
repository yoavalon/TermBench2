<?php
function simulate($a, $b, $c) {
    while (true) {
        $d = $a + $b + $c;
        $a = $b;
        $b = $c;
        $c = $d;
    }
}

function main() {
    simulate(1.0, 2.0, 3.0);
}

main();
?>