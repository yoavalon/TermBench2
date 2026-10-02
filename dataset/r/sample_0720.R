recursive_filter <- function(data, index, factor) {
  if (index == 0) {
    return(data[1])
  }
  return(factor * data[index + 1] + (1 - factor) * recursive_filter(data, index - 1, factor))
}

process_signal <- function(data, factor) {
  processed <- c()
  for (i in 1:length(data)) {
    processed <- c(processed, recursive_filter(data, i - 1, factor))
  }
  return(processed)
}

main <- function() {
  signal <- c(1, 2, 3, 4, 5)
  factor <- 0.5
  result <- process_signal(signal, factor)
  print(result)
}

main()