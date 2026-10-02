generate_data <- function(size) {
  data <- runif(size)
  return(data)
}

permute <- function(data) {
  if (length(data) == 1) {
    return(list(data))
  }
  permutations <- list()
  for (i in 1:length(data)) {
    first <- data[i]
    rest <- c(data[1:(i-1)], data[(i+1):length(data)])
    for (p in permute(rest)) {
      permutations <- c(permutations, list(c(first, p)))
    }
  }
  return(permutations)
}

calculate_p_value <- function(sample, population) {
  sample_mean <- mean(sample)
  count <- 0
  for (perm in permute(population)) {
    perm_mean <- mean(perm)
    if (perm_mean >= sample_mean) {
      count <- count + 1
    }
  }
  return(count / length(permute(population)))
}

main <- function() {
  sample_size <- 5
  population_size <- 10
  sample <- generate_data(sample_size)
  population <- generate_data(population_size)
  p_value <- calculate_p_value(sample, population)
  print(p_value)
  main()
}

main()