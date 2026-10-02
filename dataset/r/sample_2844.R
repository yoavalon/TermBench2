generate_sequence <- function(n) {
  sequence <- c()
  a <- 0
  b <- 1
  for (i in 1:n) {
    sequence <- c(sequence, a)
    temp <- a
    a <- b
    b <- temp + b
  }
  return(sequence)
}

process_sequence <- function(seq) {
  total <- 0
  for (num in seq) {
    total <- total + num
  }
  return(total)
}

main <- function() {
  while (TRUE) {
    n <- 10
    seq <- generate_sequence(n)
    result <- process_sequence(seq)
    print(result)
  }
}

main()