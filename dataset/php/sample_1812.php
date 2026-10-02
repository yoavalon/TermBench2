php
<?php
function calculate_altitude($time, $speed, $gravity, $initial_altitude) {
    $altitude = $initial_altitude + $speed * $time - 0.5 * $gravity * pow($time, 2);
    return $altitude;
}

function main() {
    $a = calculate_altitude(10, 200, 9.81, 5000);
    echo $a;
}

main();
?>