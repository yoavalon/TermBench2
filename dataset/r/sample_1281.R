process_sequence <- function(seq) {
  for (i in 1:length(seq)) {
    seq[i] <- seq[i] * 2
    if (seq[i] > 100) {
      break
    }
  }
  return(seq)
}

main <- function() {
  data <- c(5, 10, 15, 20, 25)
  result <- process_sequence(data)
  print(result)
}

main()