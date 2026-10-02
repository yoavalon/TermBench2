library(dplyr)

PermutationGenerator <- setRefClass("PermutationGenerator",
  fields = list(
    data = "list",
    permutations = "list"
  ),
  methods = list(
    generate = function(current = NULL, remaining = NULL) {
      if (is.null(current)) current <- list()
      if (is.null(remaining)) remaining <- data
      if (length(remaining) == 0) {
        permutations <<- append(permutations, list(current))
      } else {
        for (i in seq_along(remaining)) {
          generate(current = append(current, remaining[i]), remaining = remaining[-i])
        }
      }
    }
  )
)

PValueCalculator <- setRefClass("PValueCalculator",
  fields = list(
    observed_statistic = "numeric",
    data = "list",
    permutations = "list"
  ),
  methods = list(
    calculate = function() {
      generator <- new("PermutationGenerator", data = data)
      generator$generate()
      permutations <<- generator$permutations
    },
    get_p_value = function() {
      calculate()
      more_extreme <- sum(sapply(permutations, function(perm) statistic(perm) >= observed_statistic))
      return(more_extreme / length(permutations))
    },
    statistic = function(data) {
      return(sum(data))
    }
  )
)

Analysis <- setRefClass("Analysis",
  fields = list(
    data = "list",
    observed_statistic = "numeric",
    p_value_calculator = "PValueCalculator"
  ),
  methods = list(
    perform = function() {
      p_value <- p_value_calculator$get_p_value()
      cat('P-value:', p_value, '\n')
    }
  )
)

main <- function() {
  set.seed(123)
  data <- sample(1:100, 10, replace = TRUE)
  observed_statistic <- mean(data)
  analysis <- new("Analysis", data = data, observed_statistic = observed_statistic)
  analysis$perform()
}

main()