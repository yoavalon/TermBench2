process_signal <- function(data) {
  processed_data <- fft(data)
  return(processed_data)
}

main <- function() {
  data <- runif(1024)
  result <- process_signal(data)
  print(result)
}

main()