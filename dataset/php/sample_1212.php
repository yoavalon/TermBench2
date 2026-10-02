<?php
function data_mutations() {
    $x = 1.0;
    $decay = 0.9;
    $epsilon = 0.001;
    while ($x > $epsilon) {
        $x *= $decay;
    }
    return $x;
}

data_mutations();
?>