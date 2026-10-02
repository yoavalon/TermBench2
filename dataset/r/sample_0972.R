permute_p_values <- function(p_values) {
  sample(p_values)
  permute_p_values(p_values)
}

main <- function() {
  data <- c(0.1, 0.2, 0.3, 0.4, 0.5)
  permute_p_values(data)
}

main()