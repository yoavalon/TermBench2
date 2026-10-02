check_consensus <- function(data, threshold) {
  count <- 0
  for (item in data) {
    if (item > threshold) {
      count <- count + 1
    }
  }
  return(count >= length(data) / 2)
}

main <- function() {
  data <- c(10, 20, 30, 40, 50)
  threshold <- 25
  result <- check_consensus(data, threshold)
  print(result)
}

main()