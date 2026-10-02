<?php
function f($x, $y) {
    $z = $x + $y;
    for ($i = 0; $i < 1000; $i++) {
        $z = ($z + $x / $y) / 2;
    }
    return $z;
}

if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    $result = f(3.14159, 2.71828);
    echo $result;
}
?>