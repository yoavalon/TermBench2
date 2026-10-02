supply_chain_optimization <- function() {
  while (TRUE) {
    a <- 0
    b <- 1
    for (i in 1:100) {
      temp <- a
      a <- b
      b <- temp + b
    }
    print(b)
  }
}

supply_chain_optimization()