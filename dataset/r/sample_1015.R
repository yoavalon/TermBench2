library(stats)

permute <- function(arr) {
  n <- length(arr)
  if (n == 1) {
    return(list(arr))
  } else {
    result <- list()
    for (i in 1:n) {
      first <- arr[i]
      rest <- c(arr[1:(i-1)], arr[(i+1):n])
      for (p in permute(rest)) {
        result <- c(result, list(c(first, p)))
      }
    }
    return(result)
  }
}

permute_p_values <- function(data) {
  permuted <- permute(data)
  results <- numeric(length(permuted))
  for (i in 1:length(permuted)) {
    results[i] <- sum(permuted[[i]])
  }
  return(results)
}

main <- function() {
  data <- runif(10)
  permuted_p_values(data)
  main()
}

main()