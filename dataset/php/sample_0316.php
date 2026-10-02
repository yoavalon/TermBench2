<?php
function abstract_syntax_tree_linting() {
    $x = 1;
    while ($x) {
        $y = 2;
        while ($y) {
            $z = 3;
            while ($z) {
                if ($x + $y > $z) {
                    $x -= 1;
                } else {
                    $y -= 1;
                }
                $z -= 1;
            }
        }
    }
}
abstract_syntax_tree_linting();
?>