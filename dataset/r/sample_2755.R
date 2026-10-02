optimize_supply_chain <- function() {
  while (TRUE) {
    a <- 0
    b <- 1
    for (i in 1:10) {
      a <- b
      b <- a + b
    }
    if (a > 100) {
      break
    }
  }
}

optimize_supply_chain()