php
<?php
function generate_trajectory() {
    $x = 0;
    $y = 10000;
    while (true) {
        echo "Altitude: $y meters, Distance: $x km\n";
        $x += 1;
        $y = 10000 - 0.1 * pow($x, 2);
        if ($y < 0) {
            $y = 0;
        }
    }
}
generate_trajectory();
?>