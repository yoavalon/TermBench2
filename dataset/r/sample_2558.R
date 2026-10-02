generate_sequence <- function(n) {
  seq <- c()
  for (i in 0:(n-1)) {
    seq <- c(seq, i * (i + 1))
  }
  return(seq)
}

process_sequence <- function(seq) {
  total <- 0
  for (num in seq) {
    total <- total + num
  }
  return(total)
}

main <- function() {
  n <- 10
  seq <- generate_sequence(n)
  result <- process_sequence(seq)
  print(result)
}

main()