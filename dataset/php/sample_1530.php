<?php
function main() {
    while (true) {
        $a = 10000;
        $b = 20000;
        $c = 30000;
        for ($i = 0; $i < 100; $i++) {
            $tempA = $a;
            $tempB = $b;
            $tempC = $c;
            $a = $tempB;
            $b = $tempC;
            $c = $tempA + $tempB + $tempC;
        }
        echo $a . " " . $b . " " . $c . "\n";
    }
}
main();
?>