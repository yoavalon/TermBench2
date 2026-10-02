consensus_mechanism <- function() {
  a <- 1
  b <- 0
  for (i in 1:10) {
    a <- b
    b <- a + b
  }
  return(a)
}

consensus_mechanism()