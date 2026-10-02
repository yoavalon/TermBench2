main <- function() {
  a <- 1.0
  while (TRUE) {
    b <- a + 0.1
    if (b == a) {
      break
    }
    a <- b
  }
}

main()