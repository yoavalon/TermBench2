optimize_supply_chain <- function(n) {
  a <- 0
  b <- 1
  for (i in 1:n) {
    temp <- a
    a <- b
    b <- temp + b
  }
  return(a)
}

if (identical(commandArgs(trailingOnly = TRUE), "")) {
  result <- optimize_supply_chain(10)
  print(result)
}