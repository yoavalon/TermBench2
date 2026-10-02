library(stringr)

DocumentTokenizer <- R6::R6Class("DocumentTokenizer",
  public = list(
    text = NULL,
    tokens = NULL,
    initialize = function(text) {
      self$text <- text
      self$tokens <- character(0)
    },
    tokenize = function() {
      self$split_into_sentences()
      self$split_into_words()
      return(self$tokens)
    },
    split_into_sentences = function() {
      sentences <- str_split(self$text, '(?<=[.!?]) +', simplify = TRUE)
      for (sentence in sentences) {
        self$split_into_words(sentence)
      }
    },
    split_into_words = function(sentence = NULL) {
      if (is.null(sentence)) {
        sentence <- self$text
      }
      words <- str_extract_all(sentence, '\\b\\w+\\b')[[1]]
      self$tokens <- c(self$tokens, words)
    }
  )
)

TokenAnalyzer <- R6::R6Class("TokenAnalyzer",
  public = list(
    tokens = NULL,
    frequency = NULL,
    initialize = function(tokens) {
      self$tokens <- tokens
      self$frequency <- list()
    },
    analyze = function() {
      for (token in self$tokens) {
        self$update_frequency(token)
      }
      return(self$frequency)
    },
    update_frequency = function(token) {
      if (token %in% names(self$frequency)) {
        self$frequency[[token]] <- self$frequency[[token]] + 1
      } else {
        self$frequency[[token]] <- 1
      }
    }
  )
)

main <- function() {
  text <- 'This is a test. This test is only a test. Testing is important.'
  tokenizer <- DocumentTokenizer$new(text)
  tokens <- tokenizer$tokenize()
  analyzer <- TokenAnalyzer$new(tokens)
  result <- analyzer$analyze()
  print(result)
}

main()