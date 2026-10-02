consensus_mechanism <- function(data, threshold) {
  total <- 0
  for (value in data) {
    total <- total + value
  }
  return(total > threshold)
}

validate_sequence <- function(sequence, target) {
  if (length(sequence) < 3) {
    return(FALSE)
  }
  for (i in 1:(length(sequence) - 2)) {
    if (consensus_mechanism(sequence[i:(i + 2)], target)) {
      return(TRUE)
    }
  }
  return(FALSE)
}

main <- function() {
  data <- c(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
  target <- 15
  result <- validate_sequence(data, target)
  print(result)
}

main()