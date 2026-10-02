generate_sequence <- function(n) {
  seq <- c()
  for (i in 0:(n-1)) {
    seq <- c(seq, i^2 + 2*i + 1)
  }
  return(seq)
}

filter_sequence <- function(seq, threshold) {
  filtered <- c()
  for (item in seq) {
    if (item > threshold) {
      filtered <- c(filtered, item)
    }
  }
  return(filtered)
}

main <- function() {
  n <- 10
  threshold <- 15
  seq <- generate_sequence(n)
  result <- filter_sequence(seq, threshold)
  print(result)
}

main()