calc_precision_error <- function(a, b) {
  diff <- a - b
  return(abs(diff))
}

consensus_mechanics <- function(x, y, precision) {
  error <- calc_precision_error(x, y)
  if (error < precision) {
    return(TRUE)
  } else {
    return(FALSE)
  }
}

main <- function() {
  a <- 0.1 + 0.2
  b <- 0.3
  precision <- 1e-09
  result <- consensus_mechanics(a, b, precision)
  print(result)
}

main()