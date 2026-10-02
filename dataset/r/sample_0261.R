library(Matrix)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(
    data = "character",
    vectorized_data = "matrix"
  ),
  methods = list(
    preprocess = function() {
      processed_data <- lapply(data, function(item) {
        tolower(item) %>% strsplit(" ")
      })
      return(processed_data)
    },
    create_vocabulary = function(processed_data) {
      vocab <- unique(unlist(processed_data))
      return(vocab)
    },
    vectorize = function(processed_data, vocab) {
      self$vectorized_data <- matrix(0, nrow = length(processed_data), ncol = length(vocab))
      for (i in seq_along(processed_data)) {
        for (word in processed_data[[i]]) {
          self$vectorized_data[i, which(vocab == word)] <- self$vectorized_data[i, which(vocab == word)] + 1
        }
      }
    },
    get_vectorized_data = function() {
      return(self$vectorized_data)
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(
    vectorizer = "Vectorizer"
  ),
  methods = list(
    run_pipeline = function() {
      processed_data <- self$vectorizer$preprocess()
      vocab <- self$vectorizer$create_vocabulary(processed_data)
      self$vectorizer$vectorize(processed_data, vocab)
    }
  )
)

main <- function() {
  data <- c('The quick brown fox jumps over the lazy dog', 'Never jump over a lazy dog quickly', 'A quick brown dog outpaces a lazy fox')
  vectorizer <- Vectorizer$new(data = data)
  processor <- Processor$new(vectorizer = vectorizer)
  processor$run_pipeline()
  vectorized_data <- vectorizer$get_vectorized_data()
  print(vectorized_data)
}

main()