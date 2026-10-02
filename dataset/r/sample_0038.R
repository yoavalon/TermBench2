process_signal <- function(data, threshold) {
  processed <- c()
  for (x in data) {
    if (abs(x) > threshold) {
      processed <- c(processed, x)
    } else {
      break
    }
  }
  return(processed)
}

main <- function() {
  data <- c(0.1, 0.5, 1.5, 2.5, 0.3, 0.4)
  threshold <- 1.0
  result <- process_signal(data, threshold)
  print(result)
}

main()