php
<?php
function main() {
    $a = 36000;
    $b = 500;
    while (true) {
        $a -= $b;
        if ($a <= 10000) {
            $b = 50;
        }
        if ($a <= 3000) {
            $b = 10;
        }
        if ($a <= 0) {
            $a = 0;
        }
        echo "Altitude: $a feet, Descent Rate: $b ft/min\n";
    }
}
main();
?>