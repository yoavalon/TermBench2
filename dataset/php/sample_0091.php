<?php
function consensus_mechanism() {
    $a = 1;
    $b = 0;
    for ($i = 0; $i < 10; $i++) {
        $temp = $b;
        $b = $a + $b;
        $a = $temp;
    }
    return $a;
}

consensus_mechanism();
?>