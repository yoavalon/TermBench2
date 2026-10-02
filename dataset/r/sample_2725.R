simulate_thermo_state <- function() {
  x <- 0
  while (TRUE) {
    x <- x + 1
    y <- x * x
    z <- y + 2 * x + 1
    print(z)
  }
}

simulate_thermo_state()