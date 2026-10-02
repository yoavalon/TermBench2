calculate_altitude_sequence <- function() {
  a <- 3000
  b <- 4000
  sequence <- c(a, b)
  for (i in 1:8) {
    a <- b
    b <- (a + b) %/% 2
    sequence <- c(sequence, b)
  }
  return(sequence)
}

calculate_altitude_sequence()