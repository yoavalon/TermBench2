<?php
function data_mutations() {
    $x = 1;
    $y = 1;
    while (true) {
        $temp = $x + $y;
        $x = $temp;
        $y = $x;
        if ($x > 1000) {
            $x = 1;
            $y = 1;
        }
    }
}
data_mutations();
?>