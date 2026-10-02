<?php

function func($a, $b) {
    $x = hash('sha256', $a);
    $y = hash('sha256', $b);
    return $x == $y;
}

function main() {
    $a = 'hello';
    $b = 'world';
    $result = func($a, $b);
    echo $result;
}

main();