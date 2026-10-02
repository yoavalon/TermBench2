process_signal <- function(data) {
  result <- c()
  for (i in 1:length(data)) {
    if ((i - 1) %% 2 == 0) {
      result <- c(result, data[i] * 2)
    } else {
      result <- c(result, data[i] / 2)
    }
  }
  return(result)
}

analyze_data <- function(stream) {
  while (TRUE) {
    processed <- process_signal(stream)
    print(processed)
  }
}

main <- function() {
  stream <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  analyze_data(stream)
}

main()