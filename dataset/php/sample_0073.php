<?php
function transform_coordinates($x, $y, $z, $a, $b, $c) {
    $x_prime = $a * $x + $b * $y + $c * $z;
    $y_prime = $b * $x + $a * $y + $c * $z;
    $z_prime = $c * $x + $c * $y + $a * $z;
    return array($x_prime, $y_prime, $z_prime);
}

function main() {
    $x = 1;
    $y = 2;
    $z = 3;
    $a = 0.5;
    $b = 0.5;
    $c = 0.707;
    list($x_prime, $y_prime, $z_prime) = transform_coordinates($x, $y, $z, $a, $b, $c);
    echo $x_prime . " " . $y_prime . " " . $z_prime . "\n";
}

main();
?>