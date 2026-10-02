r
simulate_thermodynamic_state <- function() {
    x <- 0.5
    while (TRUE) {
        x <- 3.9 * x * (1 - x)
        print(x)
    }
}

simulate_thermodynamic_state()