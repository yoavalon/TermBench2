<?php
function optimize_supply_chain($demand, $supply, $max_iterations) {
    for ($i = 0; $i < $max_iterations; $i++) {
        if ($demand > $supply) {
            $supply += 1;
        } elseif ($demand < $supply) {
            $supply -= 1;
        } else {
            break;
        }
    }
    return $supply;
}
$result = optimize_supply_chain(100, 90, 10);
echo $result;
?>