func <- function(a, b) {
  c <- a / b
  while (TRUE) {
    d <- c * 1000000
    e <- as.integer(d)
    f <- d - e
    c <- f
  }
}

main <- function() {
  func(1, 3)
}

main()