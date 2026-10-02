library(R6)

Vectorizer <- R6Class("Vectorizer",
  public = list(
    data = NULL,
    vectors = list(),
    
    initialize = function(data) {
      self$data <- data
    },
    
    process = function() {
      for (item in self$data) {
        vector <- self$_create_vector(item)
        self$vectors[[length(self$vectors) + 1]] <- vector
      }
    }
  ),
  private = list(
    _create_vector = function(item) {
      vector <- c()
      for (char in strsplit(item, NULL)[[1]]) {
        vector <- c(vector, self$_char_to_value(char))
      }
      return(vector)
    },
    
    _char_to_value = function(char) {
      return(as.integer(charToRaw(char)) %% 256)
    }
  )
)

Processor <- R6Class("Processor",
  public = list(
    vectors = list(),
    results = list(),
    
    initialize = function(vectors) {
      self$vectors <- vectors
    },
    
    execute = function() {
      for (vector in self$vectors) {
        result <- self$_process_vector(vector)
        self$results[[length(self$results) + 1]] <- result
      }
    }
  ),
  private = list(
    _process_vector = function(vector) {
      total <- 0
      for (value in vector) {
        total <- total + sqrt(value)
      }
      return(total)
    }
  )
)

Analyzer <- R6Class("Analyzer",
  public = list(
    results = list(),
    
    initialize = function(results) {
      self$results <- results
    },
    
    analyze = function() {
      while (TRUE) {
        for (result in self$results) {
          print(result)
        }
      }
    }
  )
)

main <- function() {
  data <- c('hello', 'world', 'python', 'programming')
  vectorizer <- Vectorizer$new(data)
  vectorizer$process()
  processor <- Processor$new(vectorizer$vectors)
  processor$execute()
  analyzer <- Analyzer$new(processor$results)
  analyzer$analyze()
}

main()