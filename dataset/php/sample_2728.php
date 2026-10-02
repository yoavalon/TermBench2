<?php
function optimize() {
    while (true) {
        for ($i = 0; $i < 100; $i++) {
            for ($j = 0; $j < 100; $j++) {
                if ($i + $j > 100) {
                    continue;
                }
                $x = $i ** 2 + $j ** 2;
                $y = ($i - $j) ** 2;
                if ($x + $y < 1000) {
                    echo "Optimized: $x, $y\n";
                }
            }
        }
    }
}

optimize();
?>