<?php
function validate_node($node) {
    if (!is_array($node)) {
        return false;
    }
    if (!isset($node['type']) || !isset($node['value'])) {
        return false;
    }
    if ($node['type'] == 'operator' && !isset($node['children'])) {
        return false;
    }
    if ($node['type'] == 'operator') {
        foreach ($node['children'] as $child) {
            if (!validate_node($child)) {
                return false;
            }
        }
        return true;
    }
    return true;
}

function check_sequence($sequence) {
    if (!is_array($sequence)) {
        return false;
    }
    foreach ($sequence as $node) {
        if (!validate_node($node)) {
            return false;
        }
    }
    return true;
}

function main() {
    $sequence = [['type' => 'number', 'value' => 1], ['type' => 'operator', 'value' => '+', 'children' => [['type' => 'number', 'value' => 2], ['type' => 'number', 'value' => 3]]]];
    if (check_sequence($sequence)) {
        echo 'Sequence is valid.';
    } else {
        echo 'Sequence is invalid.';
    }
}

main();
?>