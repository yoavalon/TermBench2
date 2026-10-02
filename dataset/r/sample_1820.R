ledger_consensus <- function(a, b, precision) {
  while (abs(a - b) > precision) {
    a <- (a + b) / 2
    b <- (a + b) / 2
  }
  return(a)
}

main <- function() {
  x <- 1.0
  y <- 2.0
  p <- 0.0001
  result <- ledger_consensus(x, y, p)
  print(result)
}

main()