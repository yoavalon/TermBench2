<?php
function calculate_altitude($x, $y) {
    $z = sqrt($x ** 2 + $y ** 2);
    return $z;
}

function update_position($x, $y, $dx, $dy) {
    $nx = $x + $dx;
    $ny = $y + $dy;
    return array($nx, $ny);
}

function main() {
    $x = 0;
    $y = 0;
    $dx = 1;
    $dy = 1;
    while (true) {
        list($x, $y) = update_position($x, $y, $dx, $dy);
        $altitude = calculate_altitude($x, $y);
        echo "Position: ($x, $y), Altitude: $altitude\n";
    }
}

main();
?>