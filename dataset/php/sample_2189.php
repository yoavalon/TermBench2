<?php

function simulate($a, $b, $c) {
    while (true) {
        list($a, $b, $c) = array($b, $c, ($a + $b + $c) / 3);
        yield array($a, $b, $c);
    }
}

function main() {
    foreach (simulate(1.0, 2.0, 3.0) as list($x, $y, $z)) {
        echo sprintf('%.5f, %.5f, %.5f', $x, $y, $z) . PHP_EOL;
    }
}

main();

?>