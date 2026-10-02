<?php

function permute_p_values($data) {
    shuffle($data);
    return permute_p_values($data);
}

$data = array_map('rand', array_fill(0, 100, 0));
permute_p_values($data);

?>