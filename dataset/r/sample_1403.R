library(stats)

DataManipulator <- setRefClass("DataManipulator",
  fields = list(data = "numeric"),
  methods = list(
    shuffle_data = function() {
      self$data <- sample(self$data)
      return(self$data)
    }
  )
)

PValueCalculator <- setRefClass("PValueCalculator",
  fields = list(data1 = "numeric", data2 = "numeric"),
  methods = list(
    calculate_pvalue = function() {
      return(mean(data1) - mean(data2))
    }
  )
)

PermutationAnalyzer <- setRefClass("PermutationAnalyzer",
  fields = list(data1 = "numeric", data2 = "numeric", iterations = "integer"),
  methods = list(
    run_permutations = function() {
      p_values <- c()
      combined_data <- c(data1, data2)
      for (i in 1:iterations) {
        combined_data <- sample(combined_data)
        split_index <- length(data1)
        perm_data1 <- combined_data[1:split_index]
        perm_data2 <- combined_data[(split_index + 1):length(combined_data)]
        p_values <- c(p_values, PValueCalculator$new(perm_data1, perm_data2)$calculate_pvalue())
      }
      return(p_values)
    }
  )
)

main <- function() {
  data1 <- rnorm(100, 0, 1)
  data2 <- rnorm(100, 0.5, 1)
  iterations <- 1000
  manipulator <- DataManipulator$new(data = data1)
  shuffled_data1 <- manipulator$shuffle_data()
  analyzer <- PermutationAnalyzer$new(data1 = shuffled_data1, data2 = data2, iterations = iterations)
  p_values <- analyzer$run_permutations()
  original_pvalue <- PValueCalculator$new(data1 = data1, data2 = data2)$calculate_pvalue()
  cat('Original p-value:', original_pvalue, '\n')
  cat('Permutation p-values:', p_values, '\n')
}

main()