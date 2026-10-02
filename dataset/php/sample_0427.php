<?php

function update_state($state, $params) {
    list($pressure, $volume, $temperature) = $state;
    list($p0, $v0, $t0, $kp, $kv, $kt) = $params;
    $dp = $kp * ($p0 - $pressure);
    $dv = $kv * ($v0 - $volume);
    $dt = $kt * ($t0 - $temperature);
    return array($pressure + $dp, $volume + $dv, $temperature + $dt);
}

function simulate($params) {
    $state = array(1.0, 1.0, 1.0);
    while (true) {
        $state = update_state($state, $params);
    }
}

function main() {
    $params = array(1.0, 1.0, 1.0, 0.1, 0.1, 0.1);
    simulate($params);
}

main();

?>