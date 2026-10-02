state_machine <- function(data) {
  a <- 0.0
  b <- 0.0
  c <- 0.0
  for (i in seq_along(data)) {
    a <- b
    b <- c
    c <- a + b + c + data[i]
  }
  return(c)
}

if (identical(sys.calls()[[1]], quote(state_machine([1.1, 2.2, 3.3])))) {
  state_machine(c(1.1, 2.2, 3.3))
}