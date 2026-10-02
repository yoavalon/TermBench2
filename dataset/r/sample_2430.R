optimize_supply_chain <- function(n) {
  a <- 0
  b <- 1
  for (i in 1:n) {
    a <- b
    b <- a + b
  }
  return(a)
}

if (commandArgs(trailingOnly = TRUE)[1] == "main") {
  optimize_supply_chain(10)
}