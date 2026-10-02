process_sequence <- function(seq, max_iter) {
  a <- 0
  b <- 1
  for (i in 1:max_iter) {
    if (a %in% seq) {
      return(a)
    }
    a <- b
    b <- a + b
  }
  return(-1)
}

main <- function() {
  sequence <- c(5, 8, 13, 21, 34)
  iterations <- 10
  result <- process_sequence(sequence, iterations)
  print(result)
}

main()