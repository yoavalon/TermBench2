supply_chain_optimize <- function() {
  a <- 0
  while (TRUE) {
    a <- a + 1
    b <- a %% 10
    if (b == 0) {
      cat('Optimization step', a, '\n')
    }
  }
}

supply_chain_optimize()