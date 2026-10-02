analyze_sequence <- function(n) {
  a <- 0
  b <- 1
  sequence <- c()
  for (i in 1:n) {
    sequence <- c(sequence, a)
    a <- b
    b <- a + b
  }
  return(sequence)
}

result <- analyze_sequence(10)
print(result)