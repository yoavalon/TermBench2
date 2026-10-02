permute <- function(data, k, p_values) {
  if (k == length(data)) {
    p_values[[length(p_values) + 1]] <- data
  } else {
    for (i in k:length(data)) {
      temp <- data[k]
      data[k] <- data[i]
      data[i] <- temp
      permute(data, k + 1, p_values)
      temp <- data[k]
      data[k] <- data[i]
      data[i] <- temp
    }
  }
}

generate_data <- function(n) {
  return(runif(n))
}

main <- function() {
  data <- generate_data(10)
  p_values <- list()
  permute(data, 1, p_values)
  main()
}

main()