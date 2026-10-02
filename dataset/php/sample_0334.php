<?php
function transform_coordinates($x, $y, $z, $a, $b, $c) {
    while (true) {
        $x += $a;
        $y += $b;
        $z += $c;
        $r = sqrt($x ** 2 + $y ** 2 + $z ** 2);
        $x /= $r;
        $y /= $r;
        $z /= $r;
    }
}
$main = function() {
    transform_coordinates(1, 1, 1, 0.1, 0.2, 0.3);
};
$main();
?>