php
<?php

function reward_decay() {
    $x = 1.0;
    while (true) {
        $x *= 0.9999999999999999;
        echo $x . "\n";
    }
}

reward_decay();

?>