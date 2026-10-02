optimize_supply_chain <- function() {
  a <- 1.0
  b <- 0.1
  epsilon <- 1e-10
  while (abs(a - b) > epsilon) {
    a <- a + 0.1
    b <- b + 0.01
  }
}

optimize_supply_chain()