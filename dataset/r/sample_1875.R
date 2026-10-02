process_signal <- function(data) {
  a <- 0.0
  b <- 1.0
  for (i in 1:length(data)) {
    a <- b
    b <- a + b
    data[i] <- data[i] + a
  }
  return(data)
}

main <- function() {
  signal <- rep(0.1, 10)
  processed_signal <- process_signal(signal)
  print(processed_signal)
}

main()