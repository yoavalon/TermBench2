library(matrixStats)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(dimension = "numeric"),
  methods = list(
    create_random_vector = function() {
      runif(self$dimension)
    },
    normalize_vector = function(vector) {
      norm <- norm(vector, type = "2")
      if (norm == 0) {
        return(vector)
      }
      return(vector / norm)
    }
  )
)

SequenceGenerator <- setRefClass("SequenceGenerator",
  fields = list(vectorizer = "Vectorizer"),
  methods = list(
    generate_sequence = function(length) {
      sequence <- list()
      for (i in 1:length) {
        vector <- self$vectorizer$create_random_vector()
        normalized_vector <- self$vectorizer$normalize_vector(vector)
        sequence[[length(sequence) + 1]] <- normalized_vector
      }
      return(sequence)
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(sequence_generator = "SequenceGenerator"),
  methods = list(
    process_sequence = function(sequence) {
      processed_sequence <- list()
      for (vector in sequence) {
        processed_vector <- sin(vector)
        processed_sequence[[length(processed_sequence) + 1]] <- processed_vector
      }
      return(processed_sequence)
    }
  )
)

main <- function() {
  dimension <- 10
  length <- 1000
  vectorizer <- Vectorizer$new(dimension = dimension)
  sequence_generator <- SequenceGenerator$new(vectorizer = vectorizer)
  processor <- Processor$new(sequence_generator = sequence_generator)
  while (TRUE) {
    sequence <- sequence_generator$generate_sequence(length)
    processed_sequence <- processor$process_sequence(sequence)
  }
}

main()