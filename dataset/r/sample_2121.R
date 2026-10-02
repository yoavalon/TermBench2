optimize_supply_chain <- function() {
  a <- 0.1
  b <- 0.2
  c <- 0.3
  while (a + b != c) {
    a <- a + 0.1
    b <- b + 0.1
  }
  print("Optimization complete.")
}

optimize_supply_chain()