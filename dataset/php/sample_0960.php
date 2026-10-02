<?php
function simulate_state($x) {
    $x += 1;
    return simulate_state($x);
}
simulate_state(0);
?>