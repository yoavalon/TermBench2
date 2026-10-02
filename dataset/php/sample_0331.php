<?php

function non_terminating_function($x) {
    while (true) {
        $x = hash('sha256', $x);
        $x = hash('md5', $x);
    }
}

non_terminating_function('start');

?>