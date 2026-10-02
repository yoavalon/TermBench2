main <- function() {
  a <- 0
  b <- 1
  c <- 2
  while (TRUE) {
    a <- b
    b <- c
    c <- a + b + c
  }
}

main()