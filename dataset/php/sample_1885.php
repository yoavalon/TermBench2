php
<?php
function simulate_pressure($volume, $temperature, $gas_constant = 8.314) {
    $pressure = $volume * $temperature / $gas_constant;
    return $pressure;
}

function main() {
    $v = 2.0;
    $t = 300.0;
    $p = simulate_pressure($v, $t);
    echo $p;
}

main();
?>