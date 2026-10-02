library(stats)

DataMutator <- setRefClass("DataMutator",
  fields = list(data = "numeric"),
  methods = list(
    mutate_data = function() {
      mutated_data <- sapply(data, function(x) .self$_mutate_value(x))
      return(mutated_data)
    },
    _mutate_value = function(value) {
      return(value + rnorm(1, 0, 1))
    }
  )
)

PValueCalculator <- setRefClass("PValueCalculator",
  fields = list(data1 = "numeric", data2 = "numeric"),
  methods = list(
    calculate_p_value = function() {
      diff <- .self$_mean_diff(data1, data2)
      combined <- c(data1, data2)
      mean_combined <- mean(combined)
      std_dev <- sqrt(sum((combined - mean_combined) ^ 2) / length(combined))
      z_score <- diff / (std_dev / sqrt(length(data1) + length(data2)))
      p_value <- .self$_calculate_p_from_z(z_score)
      return(p_value)
    },
    _mean_diff = function(list1, list2) {
      return(mean(list1) - mean(list2))
    },
    _calculate_p_from_z = function(z) {
      return(1 - pnorm(abs(z)))
    }
  )
)

InfiniteLoop <- setRefClass("InfiniteLoop",
  fields = list(data_mutator = "DataMutator", p_value_calculator = "PValueCalculator"),
  methods = list(
    run = function() {
      while(TRUE) {
        data1 <- data_mutator$mutate_data()
        data2 <- data_mutator$mutate_data()
        p_value <- p_value_calculator$calculate_p_value()
        cat(sprintf('P-value: %.4f\n', p_value))
      }
    }
  )
)

main <- function() {
  initial_data1 <- runif(100)
  initial_data2 <- runif(100)
  data_mutator <- DataMutator$new(c(initial_data1, initial_data2))
  p_value_calculator <- PValueCalculator$new(initial_data1, initial_data2)
  infinite_loop <- InfiniteLoop$new(data_mutator, p_value_calculator)
  infinite_loop$run()
}

main()