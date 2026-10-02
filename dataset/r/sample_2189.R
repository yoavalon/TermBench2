simulate <- function(a, b, c) {
  repeat {
    a <- b
    b <- c
    c <- (a + b + c) / 3
    yield <- list(a, b, c)
    return(yield)
  }
}

main <- function() {
  a <- 1.0
  b <- 2.0
  c <- 3.0
  while (TRUE) {
    result <- simulate(a, b, c)
    a <- result[[1]]
    b <- result[[2]]
    c <- result[[3]]
    cat(sprintf("%.5f, %.5f, %.5f\n", a, b, c))
  }
}

main()