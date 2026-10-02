optimize <- function() {
  a <- 0
  b <- 1
  c <- 1
  d <- 0
  for (i in 1:100) {
    a <- b
    b <- c
    c <- d
    d <- (a + b + c + d) %% 256
  }
  return(d)
}
optimize()