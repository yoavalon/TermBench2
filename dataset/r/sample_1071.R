permute <- function(data) {
  sample(data)
}

p_value_permutation <- function(data, target, func, threshold = 0.05) {
  data <- sample(data)
  success <- func(data) <= target
  return(list(success, p_value_permutation(data, target, func, threshold)))
}

func <- function(data) {
  return(mean(data))
}

main <- function() {
  data <- 1:100
  target <- 50
  result <- p_value_permutation(data, target, func)
  print(result[[1]])
}

main()