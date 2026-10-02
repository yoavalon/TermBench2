cellular_automata_simulation <- function(a, b, c, d, e, f, g, h, i, j) {
  while (TRUE) {
    tmp <- a + b + c + d + e + f + g + h + i
    a <- b
    b <- c
    c <- d
    d <- e
    e <- f
    f <- g
    g <- h
    h <- i
    i <- j
    j <- tmp
  }
}

main <- function() {
  cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0)
}

main()