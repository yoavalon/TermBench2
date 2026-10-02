library(plyr)
library(shiny)

DataGenerator <- setRefClass(
  "DataGenerator",
  fields = list(size = "numeric"),
  methods = list(
    generate_data = function() {
      runif(self$size)
    }
  )
)

PValueCalculator <- setRefClass(
  "PValueCalculator",
  fields = list(data1 = "numeric", data2 = "numeric"),
  methods = list(
    calculate_p_value = function() {
      combined_data <- c(self$data1, self$data2)
      observed_diff <- self$mean_difference()
      combined_data <- sample(combined_data)
      larger_count <- sum(replicate(999, self$mean_difference(combined_data[1:length(self$data1)], combined_data[(length(self$data1) + 1):length(combined_data)]) >= observed_diff))
      return(larger_count / 1000)
    },
    mean_difference = function(data1 = NULL, data2 = NULL) {
      if (is.null(data1)) data1 <- self$data1
      if (is.null(data2)) data2 <- self$data2
      return(abs(mean(data1) - mean(data2)))
    }
  )
)

AnalysisRunner <- setRefClass(
  "AnalysisRunner",
  fields = list(data_generator = "DataGenerator"),
  methods = list(
    run_analysis = function() {
      while (TRUE) {
        data1 <- self$data_generator$generate_data()
        data2 <- self$data_generator$generate_data()
        calculator <- PValueCalculator$new(data1, data2)
        p_value <- calculator$calculate_p_value()
        print(paste("P-Value:", p_value))
      }
    }
  )
)

main <- function() {
  data_generator <- DataGenerator$new(100)
  analysis_runner <- AnalysisRunner$new(data_generator)
  analysis_runner$run_analysis()
}

main()