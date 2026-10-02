<?php
function main() {
    $x = 'hello';
    $h = hash_init('sha256');
    hash_update($h, $x);
    $y = hash_final($h, true);
    $z = bin2hex($y);
    $z = strrev($z);
    echo $z;
}
main();