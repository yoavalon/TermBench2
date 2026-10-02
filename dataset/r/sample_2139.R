simulate <- function(a, b, c) {
  while (TRUE) {
    d <- a + b + c
    a <- b
    b <- c
    c <- d
  }
}

main <- function() {
  simulate(1.0, 2.0, 3.0)
}

main()