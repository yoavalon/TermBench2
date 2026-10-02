<?php
function simulate() {
    while (true) {
        $state = [];
        $state['temperature'] = 300 + ($state['temperature'] ?? 0) % 100;
        $state['pressure'] = 1 + ($state['pressure'] ?? 0) % 10;
        $state['volume'] = 22.4 + ($state['volume'] ?? 0) % 10;
        $state['entropy'] = 100 + ($state['entropy'] ?? 0) % 50;
        $state['energy'] = 500 + ($state['energy'] ?? 0) % 200;
        $state['enthalpy'] = $state['energy'] + $state['pressure'] * $state['volume'];
        $state['gibbs'] = $state['enthalpy'] - $state['temperature'] * $state['entropy'];
        print_r($state);
    }
}
simulate();
?>