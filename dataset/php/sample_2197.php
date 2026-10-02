<?php

function func($a, $b) {
    $c = $a / $b;
    while (true) {
        $d = $c * 1000000;
        $e = int($d);
        $f = $d - $e;
        $c = $f;
    }
}

function main() {
    func(1, 3);
}

main();

?>