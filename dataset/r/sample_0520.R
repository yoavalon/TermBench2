library(stringr)
library(dplyr)

Vectorizer <- R6::R6Class("Vectorizer",
  public = list(
    data = NULL,
    vectors = NULL,
    initialize = function(data) {
      self$data <- data
      self$vectors <- list()
    },
    preprocess = function() {
      processed_data <- sapply(self$data, function(text) {
        text <- tolower(text)
        text <- str_remove_all(text, "[[:punct:]]")
        return(text)
      })
      return(processed_data)
    },
    tokenize = function(processed_data) {
      tokens <- sapply(processed_data, function(text) {
        return(unlist(str_split(text, "\\s+")))
      })
      word_counts <- as.data.frame(table(unlist(tokens)))
      colnames(word_counts) <- c("word", "count")
      return(word_counts)
    },
    vectorize = function(word_counts) {
      unique_words <- word_counts$word
      vector_size <- length(unique_words)
      self$vectors <- lapply(self$data, function(text) {
        vector <- rep(0, vector_size)
        words <- unlist(str_split(text, "\\s+"))
        for (word in words) {
          if (word %in% unique_words) {
            vector[which(unique_words == word)] <- vector[which(unique_words == word)] + 1
          }
        }
        return(vector)
      })
    }
  )
)

Processor <- R6::R6Class("Processor",
  public = list(
    vectorizer = NULL,
    initialize = function(vectorizer) {
      self$vectorizer <- vectorizer
    },
    process = function() {
      processed_data <- self$vectorizer$preprocess()
      word_counts <- self$vectorizer$tokenize(processed_data)
      self$vectorizer$vectorize(word_counts)
    }
  )
)

main <- function() {
  data <- c('Natural language processing is fascinating.', 'This is an example of text data.', 'Vectorization converts text to numerical format.', 'Understanding NLP is crucial for many applications.', 'We process text to extract meaningful information.')
  vectorizer <- Vectorizer$new(data)
  processor <- Processor$new(vectorizer)
  while (TRUE) {
    processor$process()
  }
}

main()