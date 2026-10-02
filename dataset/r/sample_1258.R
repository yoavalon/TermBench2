process_signal <- function(data, coeff) {
  for (i in 1:length(data)) {
    data[i] <- data[i] * coeff
  }
  return(data)
}

main <- function() {
  data <- c(1.0, 2.0, 3.0, 4.0, 5.0)
  coeff <- 0.5
  result <- process_signal(data, coeff)
  print(result)
}

main()