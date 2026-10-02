simulate_state <- function(n) {
  a <- 0
  b <- 1
  for (i in 1:n) {
    a <- b
    b <- a + b
  }
  return(a)
}

simulate_state(10)