sequence <- function(a, b, n) {
  if (n == 0) {
    return(a)
  } else if (n == 1) {
    return(b)
  } else {
    return(sequence(b, a + b, n - 1))
  }
}

main <- function() {
  a <- 0
  b <- 1
  n <- 10
  result <- sequence(a, b, n)
  print(result)
}

main()