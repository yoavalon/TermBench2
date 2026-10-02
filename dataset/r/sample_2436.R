main <- function() {
  n <- 10
  a <- 0
  b <- 1
  sequence <- c(a, b)
  for (i in 2:(n-1)) {
    a <- b
    b <- a + b
    sequence <- c(sequence, b)
  }
  print(sequence)
}

main()