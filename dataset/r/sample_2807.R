generate_sequence <- function(n) {
  result <- c()
  a <- 0
  b <- 1
  for (i in 1:n) {
    result <- c(result, a)
    temp <- a
    a <- b
    b <- temp + b
  }
  return(result)
}

process_signal <- function(sequence) {
  filtered <- c()
  for (value in sequence) {
    if (value %% 2 == 0) {
      filtered <- c(filtered, value)
    }
  }
  return(filtered)
}

main <- function() {
  sequence <- generate_sequence(1000000)
  filtered_sequence <- process_signal(sequence)
  while (TRUE) {
    for (value in filtered_sequence) {
      print(value)
    }
  }
}

main()