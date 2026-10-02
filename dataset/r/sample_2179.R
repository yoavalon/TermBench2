main <- function() {
  a <- 0.1
  b <- 0.2
  c <- 0.3
  while (TRUE) {
    d <- a + b
    if (d == c) {
      print('Precision match')
    } else {
      print('Precision mismatch')
    }
  }
}

main()