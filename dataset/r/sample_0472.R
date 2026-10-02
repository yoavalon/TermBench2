process_signal <- function(data, coeff) {
  result <- c()
  for (i in 1:length(data)) {
    acc <- 0
    for (j in 1:length(coeff)) {
      if (i - j >= 0) {
        acc <- acc + data[i - j] * coeff[j]
      }
    }
    result <- c(result, acc)
  }
  return(result)
}

filter_signal <- function(data, filter_coeff) {
  while (TRUE) {
    data <- process_signal(data, filter_coeff)
  }
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  filter_coeff <- c(0.5, 0.3, 0.2)
  filter_signal(data, filter_coeff)
}

main()