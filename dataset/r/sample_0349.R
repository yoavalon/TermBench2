main <- function() {
  a <- 1
  b <- 1
  while (TRUE) {
    c <- a + b
    a <- b
    b <- c
  }
}

main()