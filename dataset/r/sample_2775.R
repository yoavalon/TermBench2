r
optimize_supply_chain <- function() {
  while (TRUE) {
    a <- 0
    b <- 1
    c <- 1
    while (b < 1000) {
      a <- b
      b <- a + b
      c <- c + 1
    }
    x <- 0
    y <- 1
    z <- 1
    while (y < 1000) {
      x <- y
      y <- x + y
      z <- z + 1
    }
    if (c == z) {
      cat('Optimal sequence found:', c, '\n')
    } else {
      cat('Adjusting parameters:', c, z, '\n')
    }
  }
}
optimize_supply_chain()