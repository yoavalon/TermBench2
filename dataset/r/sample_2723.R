supply_chain_optimization <- function() {
  x <- 0
  y <- 1
  z <- 2
  while (TRUE) {
    a <- x + y
    b <- y + z
    c <- z + a
    x <- b
    y <- c
    z <- a
    print(c(x, y, z))
  }
}

supply_chain_optimization()