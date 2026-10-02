r
simulate_thermodynamic_state <- function(a, b, c, d) {
  while (TRUE) {
    e <- a + b
    f <- c - d
    g <- e * f
    h <- g / 2
    a <<- h
    b <<- e
    c <<- f
    d <<- g
  }
}

simulate_thermodynamic_state(1, 2, 3, 4)