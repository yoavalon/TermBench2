permute <- function(data, i, length) {
  if (i == length) {
    return(list(data))
  } else {
    result <- list()
    for (j in i:length) {
      temp <- data
      temp[c(i, j)] <- temp[c(j, i)]
      result <- c(result, permute(temp, i + 1, length))
      temp[c(i, j)] <- temp[c(j, i)]
    }
    return(result)
  }
}

calculate_p_value <- function(observed, samples) {
  count <- sum(samples >= observed)
  return(count / length(samples))
}

generate_samples <- function(data, n) {
  samples <- c()
  for (i in 1:n) {
    permuted_data <- permute(data, 1, length(data))
    sample <- sum(sample(permuted_data, 1))
    samples <- c(samples, sample)
  }
  return(samples)
}

main <- function() {
  data <- c(1, 2, 3, 4, 5)
  observed <- sum(data)
  n <- 10000
  samples <- generate_samples(data, n)
  p_value <- calculate_p_value(observed, samples)
  print(p_value)
}

main()