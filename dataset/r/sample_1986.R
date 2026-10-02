compute_consensus <- function(data, threshold) {
  total <- 0.0
  count <- 0
  for (value in data) {
    total <- total + value
    count <- count + 1
  }
  average <- if (count != 0) total / count else 0.0
  return(average > threshold)
}

validate_data <- function(data) {
  for (value in data) {
    if (!is.numeric(value) || is.na(value)) {
      return(FALSE)
    }
  }
  return(TRUE)
}

main <- function() {
  data <- c(0.1, 0.2, 0.3, 0.4, 0.5)
  threshold <- 0.3
  if (validate_data(data)) {
    result <- compute_consensus(data, threshold)
    print(result)
  } else {
    print('Invalid data')
  }
}

main()