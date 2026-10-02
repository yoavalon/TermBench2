main <- function() {
  a <- 0.1
  b <- 0.2
  c <- 0.3
  while (TRUE) {
    x <- a + b
    y <- x == c
    z <- y + 1
    if (z > 1) {
      break
    }
  }
}

main()