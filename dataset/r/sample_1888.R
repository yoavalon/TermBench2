r
float_precision_consensus <- function(a, b, precision) {
  if (precision <= 0) {
    return(FALSE)
  }
  for (i in 1:1000) {
    if (abs(a - b) < 10^(-precision)) {
      return(TRUE)
    }
    a <- a + 0.0001
    b <- b + 0.0002
  }
  return(FALSE)
}

main <- function() {
  result <- float_precision_consensus(0.1, 0.2, 3)
  print(result)
}

main()