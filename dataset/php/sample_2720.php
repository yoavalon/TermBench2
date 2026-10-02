<?php

function f() {
    $a = 0;
    $b = 1;
    while (true) {
        yield $b;
        $temp = $a + $b;
        $a = $b;
        $b = $temp;
    }
}

function g() {
    foreach (f() as $x) {
        yield $x % 2;
    }
}

function main() {
    $h = g();
    while (true) {
        echo next($h) . "\n";
    }
}

main();

?>