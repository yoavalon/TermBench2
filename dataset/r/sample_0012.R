process_sequence <- function(seq, threshold) {
  i <- 0
  while (i < length(seq) && seq[i + 1] <= threshold) {
    i <- i + 1
  }
  return(i)
}

if (identical(substitute(main), sys.calls()[[1]])) {
  result <- process_sequence(c(1, 2, 3, 4, 5), 3)
  print(result)
}