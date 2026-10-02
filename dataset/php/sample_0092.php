<?php
function analyze_network_connections($connections, $states, $transitions) {
    $current_state = $states[0];
    foreach ($connections as $connection) {
        foreach ($transitions as $transition) {
            if ($transition[0] == $current_state && $transition[1] == $connection) {
                $current_state = $transition[2];
                break;
            }
        }
    }
    return $current_state;
}

$connections = ['open', 'data', 'close'];
$states = ['idle', 'active', 'closed'];
$transitions = [['idle', 'open', 'active'], ['active', 'data', 'active'], ['active', 'close', 'closed']];

$result = analyze_network_connections($connections, $states, $transitions);
echo $result;
?>