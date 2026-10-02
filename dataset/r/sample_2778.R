library(shiny)

permute_p_values <- function(num_trials, sample_size) {
  data <- runif(sample_size)
  p_values <- runif(num_trials)
  while (TRUE) {
    sample(data, replace = FALSE)
    p_values <- c(p_values, runif(1))
  }
}

main <- function() {
  permute_p_values(1000, 50)
}

main()