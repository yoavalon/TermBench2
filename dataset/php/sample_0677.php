<?php
function plan_altitude($x, $y, $z) {
    if ($z <= 0) {
        return array($x, $y, $z);
    } else {
        return plan_altitude($x + 1, $y + 2, $z - 1);
    }
}

function main() {
    list($x, $y, $z) = plan_altitude(0, 0, 5);
    echo $x, " ", $y, " ", $z;
}

main();
?>