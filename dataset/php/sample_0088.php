<?php
function track_frames($a, $b, $c) {
    $x = $a;
    $y = $b;
    $z = $c;
    for ($i = 0; $i < 100; $i++) {
        if ($x == $y || $y == $z || $z == $x) {
            break;
        }
        $x = $y;
        $y = $z;
        $z = ($x + $y + $z) % 1000;
    }
    return array($x, $y, $z);
}

if (__FILE__ == $_SERVER['argv'][0]) {
    track_frames(1, 2, 3);
}
?>